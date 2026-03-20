#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <ctime>
#include <unordered_set>
using namespace std;

/*
    Very Advanced (Console) Hotel Management System in C++
    Features:
    - Room types with different rates and capacities
    - Customer and Reservation management
    - Check-in / Check-out
    - Search reservations (by customer name, ID)
    - Simple billing (base price + tax + optional services)
    - Basic persistence (load/save to files)
    - Console-only menus
*/

struct Date {
    int year{}, month{}, day{};

    bool operator<(const Date &o) const {
        if (year != o.year) return year < o.year;
        if (month != o.month) return month < o.month;
        return day < o.day;
    }

    bool operator==(const Date &o) const {
        return year == o.year && month == o.month && day == o.day;
    }

    bool operator<=(const Date &o) const {
        return (*this < o) || (*this == o);
    }

    static Date fromString(const string &s) {
        Date d;
        sscanf(s.c_str(), "%d-%d-%d", &d.year, &d.month, &d.day);
        return d;
    }

    string toString() const {
        char buf[16];
        snprintf(buf, sizeof(buf), "%04d-%02d-%02d", year, month, day);
        return string(buf);
    }
};

struct Room {
    int id{};
    string type;
    int capacity{};
    double baseRate{};
    bool active{true};

    string serialize() const {
        ostringstream oss;
        oss << id << "|" << type << "|" << capacity << "|" << baseRate << "|" << active;
        return oss.str();
    }

    static Room deserialize(const string &line) {
        Room r;
        string token;
        stringstream ss(line);
        getline(ss, token, '|'); r.id = stoi(token);
        getline(ss, r.type, '|');
        getline(ss, token, '|'); r.capacity = stoi(token);
        getline(ss, token, '|'); r.baseRate = stod(token);
        getline(ss, token, '|'); r.active = (token == "1" || token == "true");
        return r;
    }
};

struct Customer {
    int id{};
    string name;
    string phone;
    string email;
    string idNumber;

    string serialize() const {
        ostringstream oss;
        oss << id << "|" << name << "|" << phone << "|" << email << "|" << idNumber;
        return oss.str();
    }

    static Customer deserialize(const string &line) {
        Customer c;
        string token;
        stringstream ss(line);
        getline(ss, token, '|'); c.id = stoi(token);
        getline(ss, c.name, '|');
        getline(ss, c.phone, '|');
        getline(ss, c.email, '|');
        getline(ss, c.idNumber, '|');
        return c;
    }
};

enum class ReservationStatus {
    RESERVED, CHECKED_IN, COMPLETED, CANCELLED
};

static string statusToString(ReservationStatus s) {
    switch (s) {
        case ReservationStatus::RESERVED: return "RESERVED";
        case ReservationStatus::CHECKED_IN: return "CHECKED_IN";
        case ReservationStatus::COMPLETED: return "COMPLETED";
        case ReservationStatus::CANCELLED: return "CANCELLED";
    }
    return "UNKNOWN";
}

static ReservationStatus stringToStatus(const string &s) {
    if (s == "RESERVED") return ReservationStatus::RESERVED;
    if (s == "CHECKED_IN") return ReservationStatus::CHECKED_IN;
    if (s == "COMPLETED") return ReservationStatus::COMPLETED;
    if (s == "CANCELLED") return ReservationStatus::CANCELLED;
    return ReservationStatus::RESERVED;
}

struct Reservation {
    int id{};
    int roomId{};
    int customerId{};
    Date checkIn;
    Date checkOut;
    int guests{};
    ReservationStatus status{ReservationStatus::RESERVED};
    double totalBill{};
    string notes;

    string serialize() const {
        ostringstream oss;
        oss << id << "|" << roomId << "|" << customerId << "|" << checkIn.toString()
            << "|" << checkOut.toString() << "|" << guests << "|"
            << statusToString(status) << "|" << totalBill << "|" << notes;
        return oss.str();
    }

    static Reservation deserialize(const string &line) {
        Reservation r;
        string token;
        stringstream ss(line);

        getline(ss, token, '|'); r.id = stoi(token);
        getline(ss, token, '|'); r.roomId = stoi(token);
        getline(ss, token, '|'); r.customerId = stoi(token);
        getline(ss, token, '|'); r.checkIn = Date::fromString(token);
        getline(ss, token, '|'); r.checkOut = Date::fromString(token);
        getline(ss, token, '|'); r.guests = stoi(token);
        getline(ss, token, '|'); r.status = stringToStatus(token);
        getline(ss, token, '|'); r.totalBill = stod(token);
        getline(ss, r.notes);
        return r;
    }

    int nights() const {
        tm a = {}; tm b = {};
        a.tm_year = checkIn.year - 1900; a.tm_mon = checkIn.month - 1; a.tm_mday = checkIn.day;
        b.tm_year = checkOut.year - 1900; b.tm_mon = checkOut.month - 1; b.tm_mday = checkOut.day;
        time_t ta = mktime(&a), tb = mktime(&b);
        if (ta == -1 || tb == -1) return 1;
        double diff = difftime(tb, ta) / (60*60*24);
        return max(1, (int)round(diff));
    }
};

class HotelDatabase {
    vector<Room> rooms;
    vector<Customer> customers;
    vector<Reservation> reservations;
    int nextRoomId{1}, nextCustomerId{1}, nextReservationId{1};
    string roomsFile{"rooms.db"}, customersFile{"customers.db"}, reservationsFile{"reservations.db"};

public:
    HotelDatabase() { loadAll(); if (rooms.empty()) { seedDefaultRooms(); saveRooms(); } }

    // Room
    const vector<Room>& getRooms() const { return rooms; }
    Room* findRoomById(int id) { for (auto &r : rooms) if (r.id == id) return &r; return nullptr; }
    void addRoom(const string &type, int cap, double rate) { rooms.push_back({nextRoomId++, type, cap, rate, true}); saveRooms(); }

    // Customer
    Customer* findCustomerById(int id) { for (auto &c : customers) if (c.id == id) return &c; return nullptr; }
    vector<Customer*> findCustomersByName(const string &namePart) {
        vector<Customer*> res;
        for (auto &c : customers) {
            string n = c.name; string np = namePart;
            transform(n.begin(), n.end(), n.begin(), ::tolower);
            transform(np.begin(), np.end(), np.begin(), ::tolower);
            if (n.find(np) != string::npos) res.push_back(&c);
        }
        return res;
    }
    Customer* createCustomer(const string &name, const string &phone, const string &email, const string &idNum) {
        customers.push_back({nextCustomerId++, name, phone, email, idNum});
        saveCustomers();
        return &customers.back();
    }
    const vector<Customer>& getAllCustomers() const { return customers; }

    // Reservation
    Reservation* findReservationById(int id) { for (auto &r : reservations) if (r.id == id) return &r; return nullptr; }
    vector<Reservation*> findReservationsByCustomerId(int cid) {
        vector<Reservation*> res; for (auto &r : reservations) if (r.customerId == cid) res.push_back(&r); return res;
    }
    vector<Reservation*> findReservationsByCustomerName(const string &namePart) {
        vector<Reservation*> res; auto matches = findCustomersByName(namePart);
        unordered_set<int> ids; for (auto *c : matches) ids.insert(c->id);
        for (auto &r : reservations) if (ids.count(r.customerId)) res.push_back(&r);
        return res;
    }
    bool isRoomAvailable(int roomId, const Date &in, const Date &out, int ignoreResId=-1) {
        for (auto &r : reservations) {
            if (r.roomId != roomId || r.id == ignoreResId) continue;
            if (r.status == ReservationStatus::CANCELLED || r.status == ReservationStatus::COMPLETED) continue;
            if (!(out <= r.checkIn || r.checkOut <= in)) return false;
        }
        return true;
    }
    Reservation* createReservation(int roomId, int customerId, const Date &in, const Date &out, int guests, const string &notes) {
        reservations.push_back({nextReservationId++, roomId, customerId, in, out, guests, ReservationStatus::RESERVED, 0.0, notes});
        saveReservations();
        return &reservations.back();
    }
    void updateReservation(const Reservation &r) { for (auto &x : reservations) if (x.id == r.id) { x = r; break; } saveReservations(); }
    const vector<Reservation>& getAllReservations() const { return reservations; }

    double calculateBaseBill(const Reservation &res) {
        Room *room = findRoomById(res.roomId); if (!room) return 0.0; return room->baseRate * res.nights();
    }
    double calculateTotalBill(const Reservation &res, double extra=0.0, double tax=0.1) { double b = calculateBaseBill(res); return b+extra+(b+extra)*tax; }

    // Persistence
    void loadAll() { loadRooms(); loadCustomers(); loadReservations(); updateNextIds(); }
    void saveAll() { saveRooms(); saveCustomers(); saveReservations(); }

private:
    void updateNextIds() {
        for (auto &r: rooms) nextRoomId = max(nextRoomId, r.id+1);
        for (auto &c: customers) nextCustomerId = max(nextCustomerId, c.id+1);
        for (auto &r: reservations) nextReservationId = max(nextReservationId, r.id+1);
    }
    void seedDefaultRooms() { addRoom("Standard",2,80); addRoom("Deluxe",3,120); addRoom("Suite",4,200); }
    void loadRooms() { rooms.clear(); ifstream in(roomsFile); string line; while(getline(in,line)) if(!line.empty()) rooms.push_back(Room::deserialize(line)); }
    void saveRooms() { ofstream out(roomsFile); for(auto &r: rooms) out<<r.serialize()<<"\n"; }
    void loadCustomers() { customers.clear(); ifstream in(customersFile); string line; while(getline(in,line)) if(!line.empty()) customers.push_back(Customer::deserialize(line)); }
    void saveCustomers() { ofstream out(customersFile); for(auto &c: customers) out<<c.serialize()<<"\n"; }
    void loadReservations() { reservations.clear(); ifstream in(reservationsFile); string line; while(getline(in,line)) if(!line.empty()) reservations.push_back(Reservation::deserialize(line)); }
    void saveReservations() { ofstream out(reservationsFile); for(auto &r: reservations) out<<r.serialize()<<"\n"; }
};

// ======= Utility =======
int readInt(const string &prompt) { int x; cout<<prompt; while(!(cin>>x)){cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); cout<<"Invalid number. Try again: ";} cin.ignore(numeric_limits<streamsize>::max(),'\n'); return x; }
double readDouble(const string &prompt) { double x; cout<<prompt; while(!(cin>>x)){cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); cout<<"Invalid number. Try again: ";} cin.ignore(numeric_limits<streamsize>::max(),'\n'); return x; }
string readLine(const string &prompt) { cout<<prompt; string s; getline(cin,s); return s; }
Date readDate(const string &prompt) { while(true){string s = readLine(prompt+" (YYYY-MM-DD): "); if(s.size()==10 && s[4]=='-' && s[7]=='-'){Date d=Date::fromString(s); if(d.year>1900 && d.month>=1 && d.month<=12 && d.day>=1 && d.day<=31) return d;} cout<<"Invalid date format. Try again.\n";} }

// ======= Menus =======
void listRooms(HotelDatabase &db){ cout<<"\n--- Rooms ---\n"; for(auto &r: db.getRooms()) cout<<"ID: "<<r.id<<" | "<<r.type<<" | Capacity: "<<r.capacity<<" | Rate: $"<<r.baseRate<<" | Active: "<<(r.active?"Yes":"No")<<"\n"; }
void addRoomMenu(HotelDatabase &db){ string t=readLine("Room Type: "); int c=readInt("Capacity: "); double r=readDouble("Rate: "); db.addRoom(t,c,r); cout<<"Room added.\n"; }

Customer* selectOrCreateCustomer(HotelDatabase &db){
    cout<<"1. Search existing\n2. Create new\n"; int ch=readInt("Choose: ");
    if(ch==1){ string q=readLine("Name search: "); auto res=db.findCustomersByName(q); if(res.empty()){cout<<"No customers found.\n"; return nullptr;} cout<<"Matches:\n"; for(auto*c:res) cout<<"ID:"<<c->id<<" | "<<c->name<<" | "<<c->phone<<"\n"; int id=readInt("Enter ID: "); Customer* c=db.findCustomerById(id); if(!c) cout<<"Invalid ID.\n"; return c;}
    string name=readLine("Name: "); string phone=readLine("Phone: "); string email=readLine("Email: "); string idnum=readLine("ID/Passport: ");
    Customer *c=db.createCustomer(name, phone, email, idnum); cout<<"Customer created with ID: "<<c->id<<"\n"; return c;
}

void createReservationMenu(HotelDatabase &db){
    listRooms(db); int rid=readInt("Select Room ID: "); Room* room=db.findRoomById(rid); if(!room){cout<<"Invalid room.\n"; return;}
    Customer* cust=selectOrCreateCustomer(db); if(!cust) return;
    Date in=readDate("Check-in date"), out=readDate("Check-out date"); if(!(in<out)){cout<<"Check-out must be after check-in.\n"; return;}
    int guests=readInt("Number of guests: "); string notes=readLine("Notes: ");
    if(!db.isRoomAvailable(rid,in,out)){cout<<"Room not available for those dates.\n"; return;}
    Reservation* res=db.createReservation(rid,cust->id,in,out,guests,notes);
    double total=db.calculateTotalBill(*res); cout<<"Reservation created. Total estimate: $"<<total<<"\n";
}

void listReservations(HotelDatabase &db){ cout<<"\n--- Reservations ---\n"; for(auto &r: db.getAllReservations()) cout<<"ID:"<<r.id<<" | Room:"<<r.roomId<<" | Customer:"<<r.customerId<<" | "<<r.checkIn.toString()<<" to "<<r.checkOut.toString()<<" | Guests:"<<r.guests<<" | Status:"<<statusToString(r.status)<<"\n"; }

void mainMenu(HotelDatabase &db){
    while(true){
        cout<<"\n--- Hotel Management ---\n1. List Rooms\n2. Add Room\n3. Create Reservation\n4. List Reservations\n5. Exit\n";
        int ch=readInt("Choice: ");
        switch(ch){
            case 1: listRooms(db); break;
            case 2: addRoomMenu(db); break;
            case 3: createReservationMenu(db); break;
            case 4: listReservations(db); break;
            case 5: db.saveAll(); cout<<"Goodbye!\n"; return;
            default: cout<<"Invalid choice.\n";
        }
    }
}

int main(){ HotelDatabase db; mainMenu(db); return 0; }
