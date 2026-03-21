import tkinter as tk
from tkinter import messagebox
import json

class Book:
    def __init__(self, id, title, author):
        self.id = id
        self.title = title
        self.author = author
        self.issued_to = None

class Student:
    def __init__(self, name):
        self.name = name
        self.books = []

def save_data(library, filename):
    with open(filename, 'w') as file:
        json.dump(library.__dict__, file)

def load_data(filename):
    with open(filename, 'r') as file:
        data = json.load(file)
        library = BookLibrary()
        for book in data['books']:
            library.add_book(Book(**book))
        return library

class BookLibrary:
    def __init__(self):
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def search_by_title(self, title):
        for book in self.books:
            if book.title == title:
                return book
        return None

    def search_by_author(self, author):
        for book in self.books:
            if book.author == author:
                return book
        return None

    def search_by_id(self, id):
        for book in self.books:
            if book.id == id:
                return book
        return None

    def issue_book(self, student, book):
        if book.issued_to is None:
            book.issued_to = student
            student.books.append(book)
            messagebox.showinfo("Book Issued", f"{student.name} has been issued {book.title}.")
        else:
            messagebox.showerror("Error", "This book is already issued to someone.")

    def return_book(self, student, book):
        if book in student.books and book.issued_to == student.name:
            book.issued_to = None
            student.books.remove(book)
            messagebox.showinfo("Book Returned", f"{student.name} has returned {book.title}.")
        else:
            messagebox.showerror("Error", "This book is not issued to the given student.")

def create_gui(library):
    root = tk.Tk()
    root.title("Library Management System")

    def add_book():
        title = entry_title.get()
        author = entry_author.get()
        id_ = int(entry_id.get())
        library.add_book(Book(id_, title, author))
        save_data(library, "library.json")

    def search_by_title():
        title = entry_search_title.get()
        book = library.search_by_title(title)
        if book:
            messagebox.showinfo("Book Found", f"{book.title} by {book.author}")
        else:
            messagebox.showerror("Error", "No such book found.")

    def search_by_author():
        author = entry_search_author.get()
        book = library.search_by_author(author)
        if book:
            messagebox.showinfo("Book Found", f"{book.title} by {book.author}")
        else:
            messagebox.showerror("Error", "No such author found.")

    def search_by_id():
        id_ = int(entry_search_id.get())
        book = library.search_by_id(id_)
        if book:
            messagebox.showinfo("Book Found", f"{book.title} by {book.author}")
        else:
            messagebox.showerror("Error", "No such ID found.")

    def issue_book():
        book = library.search_by_id(int(entry_issue_id.get()))
        if book:
            student = Student(entry_student.get())
            library.issue_book(student, book)
            save_data(library, "library.json")
        else:
            messagebox.showerror("Error", "No such book found.")

    def return_book():
        book = library.search_by_id(int(entry_return_id.get()))
        if book:
            student = Student(entry_student.get())
            library.return_book(student, book)
            save_data(library, "library.json")
        else:
            messagebox.showerror("Error", "No such book found.")

    frame = tk.Frame(root)
    frame.pack(padx=10, pady=10)

    label_title = tk.Label(frame, text="Add Book")
    label_title.grid(row=0, column=0)
    entry_id = tk.Entry(frame)
    entry_id.grid(row=1, column=0)
    entry_title = tk.Entry(frame)
    entry_title.grid(row=2, column=0)
    entry_author = tk.Entry(frame)
    entry_author.grid(row=3, column=0)
    button_add = tk.Button(frame, text="Add", command=add_book)
    button_add.grid(row=4, column=0)

    label_search = tk.Label(frame, text="Search")
    label_search.grid(row=5, column=0)
    frame2 = tk.Frame(root)
    frame2.grid(row=6, columnspan=2)

    label_search_title = tk.Label(frame2, text="Title")
    label_search_title.grid(row=0, column=0)
    entry_search_title = tk.Entry(frame2)
    entry_search_title.grid(row=0, column=1)
    button_search_title = tk.Button(frame2, text="Search", command=search_by_title)
    button_search_title.grid(row=0, column=2)

    label_search_author = tk.Label(frame2, text="Author")
    label_search_author.grid(row=1, column=0)
    entry_search_author = tk.Entry(frame2)
    entry_search_author.grid(row=1, column=1)
    button_search_author = tk.Button(frame2, text="Search", command=search_by_author)
    button_search_author.grid(row=1, column=2)

    label_search_id = tk.Label(frame2, text="ID")
    label_search_id.grid(row=2, column=0)
    entry_search_id = tk.Entry(frame2)
    entry_search_id.grid(row=2, column=1)
    button_search_id = tk.Button(frame2, text="Search", command=search_by_id)
    button_search_id.grid(row=2, column=2)

    label_issue = tk.Label(frame2, text="Issue Book")
    label_issue.grid(row=3, column=0)
    entry_student = tk.Entry(frame2)
    entry_student.grid(row=4, column=0)
    entry_issue_id = tk.Entry(frame2)
    entry_issue_id.grid(row=5, column=0)
    button_issue = tk.Button(frame2, text="Issue", command=issue_book)
    button_issue.grid(row=6, column=0)

    label_return = tk.Label(frame2, text="Return Book")
    label_return.grid(row=7, column=0)
    entry_student = tk.Entry(frame2)
    entry_student.grid(row=8, column=0)
    entry_return_id = tk.Entry(frame2)
    entry_return_id.grid(row=9, column=0)
    button_return = tk.Button(frame2, text="Return", command=return_book)
    button_return.grid(row=10, column=0)

    root.mainloop()

library = load_data("library.json") or BookLibrary()
create_gui(library)
