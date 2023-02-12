import java.util.Scanner;
//LibraryManagementSystem
public class LibraryManagementSystem {
  static Scanner input = new Scanner(System.in);

  static int numberOfBooks = 0;
  static String[] bookTitle = new String[10];
  static String[] authorName = new String[10];
  static boolean[] isBookAvailable = new boolean[10];

  public static void main(String[] args) {
    int userChoice;
    do {
      displayMenu();
      userChoice = input.nextInt();
      switch (userChoice) {
        case 1:
          addBook();
          break;
        case 2:
          searchBook();
          break;
        case 3:
          issueBook();
          break;
        case 4:
          returnBook();
          break;
        case 5:
          listAllBooks();
          break;
        case 6:
          System.out.println("Exiting the system...");
          System.exit(0);
        default:
          System.out.println("Invalid choice! Please try again.");
          break;
      }
    } while (userChoice != 6);
  }

  static void displayMenu() {
    System.out.println("Welcome to Library Management System");
    System.out.println("1. Add a book");
    System.out.println("2. Search a book");
    System.out.println("3. Issue a book");
    System.out.println("4. Return a book");
    System.out.println("5. List all books");
    System.out.println("6. Exit");
    System.out.print("Enter your choice: ");
  }

  static void addBook() {
    if (numberOfBooks == 10)
    {
      System.out.println("Sorry, the library is full. Cannot add more books.");
      return;
    }
    System.out.print("Enter the title of the book: ");
    input.nextLine();
    
    bookTitle[numberOfBooks] = input.nextLine();
    System.out.print("Enter the name of the author: ");
    
    authorName[numberOfBooks] = input.nextLine();
    isBookAvailable[numberOfBooks] = true;
    
    numberOfBooks++;
    System.out.println("Book added successfully.");
  }

  static void searchBook()
  {
    System.out.print("Enter the title of the book: ");
    input.nextLine();
    
    String title = input.nextLine();
    int index = -1;
    
    for (int i = 0; i < numberOfBooks; i++)
    {
      if (bookTitle[i].equalsIgnoreCase(title))
      {
        index = i;
        break;
      }
    }
    if (index == -1)
    {
      System.out.println("Sorry, the book is not found.");
    } 
    else 
    {
      System.out.println("Book found!");
      System.out.println("Title: " + bookTitle[index]);
      System.out.println("Author: " + authorName[index]);
      System.out.println("Availability: " + (isBookAvailable[index] ? "Available" : "Not Available"));
    }
  }
    static void issueBook()
    {
        System.out.print("Enter the title of the book: ");
        input.nextLine();
        String title = input.nextLine();
        int index = -1;
        for(int i = 0; i < numberOfBooks; i++)
        {
           if(bookTitle[i].equalsIgnoreCase(title))
           {
               index = i;
               break;
           }
        }
        if(index == -1)
        {
            System.out.println("Sorry, the book is not found.");
        }
        else
        {
            if(!isBookAvailable[index])
            {
                System.out.println("Sorry, the book is not available.");
            }
            else
            {
                isBookAvailable[index] = false;
                System.out.println("Book issued successfully.");
            }
        }
    }

    static void returnBook()
    {
        System.out.print("Enter the title of the book: ");
        input.nextLine();
        String title = input.nextLine();
        int index = -1;
        for(int i = 0; i < numberOfBooks; i++)
        {
           if(bookTitle[i].equalsIgnoreCase(title))
           {
               index = i;
               break;
           }
        }
        if(index == -1)
        {
            System.out.println("Sorry, the book is not found.");
        }
        else
        {
            if(isBookAvailable[index])
            {
                System.out.println("Sorry, the book is already available.");
            }
            else
            {
                isBookAvailable[index] = true;
                System.out.println("Book returned successfully.");
            }
        }
    }

  static void listAllBooks()
  {
      if(numberOfBooks == 0)
      {
          System.out.println("No books found in the library.");
      }
      else
      {
          System.out.println("List of all books in the library:");
          for(int i = 0; i < numberOfBooks; i++)
          {
                System.out.println((i + 1) + ". Title: " + bookTitle[i]);
                System.out.println("   Author: " + authorName[i]);
                System.out.println("   Availability: " + (isBookAvailable[i] ? "Available" : "Not Available"));
          }
       }
   }
}
