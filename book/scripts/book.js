class Book{
    constructor(id,title,author,price){
        this.id = id;
        this.title = title;
        this.author = author;
        this.price = price;
    }
}
class BookCollection{
    constructor(){
        this.books = [];
    }
    insertBook(book){
        this.books.push(book);
        alert("Book Added!");
    }
    deleteBook(bookId){
        for (var i = 0; i < this.books.length; i++) {
			if(this.books[i].id == bookId){
				this.books.splice(i, 1);
				alert("Book deleted successfully");
			}
		}
		throw "Book not found to delete";
    }
    updateBook(book){

    }
    getAllBooks(){
        var len = this.books.length;
        if(len == 1 ){
            var bookEntry = this.books[0];
            var tr = '<tr><td>' + bookEntry.id + '</td><td>';
            tr += bookEntry.title + '</td><td>';
            tr += bookEntry.author + '</td><td>';
            tr += bookEntry.price + '</td></tr>';
            document.getElementById("bTable").innerHTML += tr;
        }else{
            len = this.books.length-1;
            var bookEntry = this.books[len];
            var tr = '<tr><td>' + bookEntry.id + '</td><td>';
            tr += bookEntry.title + '</td><td>';
            tr += bookEntry.author + '</td><td>';
            tr += bookEntry.price + '</td></tr>';
            document.getElementById("bTable").innerHTML += tr;
        }
    }
    findBook(bookId){
        for (var i = 0; i < this.books.length; i++) {
			if(this.books[i].id == bookId){
				return this.books[i];
			}
        }
        throw("Book not Found!");
    }
    displayBook(){
        var bookData = "Id: "+ this.id+"<br>"+"Title: "+this.title+"<br>"+"Book Author: "+this.author+"<br>"+"Book Price: "+this.price;
        var display = document.getElementById("data");
        display.innerHTML=bookData;
    }
}
