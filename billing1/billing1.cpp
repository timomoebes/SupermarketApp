#include <iostream> // We include the iostream library for input and output operations.
#include <fstream>  // The fstream library is used for file operations, like reading and writing files.

using namespace std; // This makes it easier to write code without having to prefix everything with 'std::'.

// The 'shopping' class - it's like a blueprint for our shopping system.
class shopping
{

private:
	// Private variables - these can only be used within the class.
	int pcode; // Product code
	float price; // Price of the product
	float dis; // Discount on the product
	string pname; // Name of the product

public:
	// Public functions - these can be called from outside the class.
	void menu(); // Displays the main menu.
	void administrator(); // Menu for administrators.
	void buyer(); // Menu for buyers.
	void add(); // Adds a new product.
	void edit(); // Edits an existing product.
	void rem(); // Removes a product.
	void list(); // Lists all products.
	void receipt(); // Generates a receipt.

};

// Function to display the main menu.
void shopping::menu() 
{
	m: // A label for the goto statement.
	int choice; // Here we store the user's choice.
	string email; // For the administrator's email.
	string password; // For the administrator's password.

	// Displaying the menu.
	cout << "\t\t\t\t___________________________________\n";
	cout << "\t\t\t\t                                   \n";
	cout << "\t\t\t\t       Supermarket Main Menu       \n";
	cout << "\t\t\t\t                                   \n";
	cout << "\t\t\t\t___________________________________\n";
	cout << "\t\t\t\t                                   \n";

	// Menu options.
	cout << "\t\t\t\t |   1)      Administrator   |\n";
	cout << "\t\t\t\t |                           |\n";
	cout << "\t\t\t\t |   2)      Buyer           |\n";
	cout << "\t\t\t\t |                           |\n";
	cout << "\t\t\t\t |   3)      Exit            |\n";
	cout << "\n\t\t\t Please select!";
	cin >> choice; // Reading the user's choice.

	// Decisions based on user's choice.
	switch (choice) 
	{
		case 1: // Case 1: Administrator.
			cout << "\t\t\t Please login \n";
			cout << "\t\t\t Enter email   \n";
			cin >> email; // Reading the email.
			cout << "\t\t\t Password       \n";
			cin >> password; // Reading the password.

			// Checking if email and password are correct.
			if (email == "ricky@email.com" && password == "ricky@11")
			{
				administrator(); // Calling the administrator menu.
			}
			else {
				cout << "Invalid email/password"; // Wrong email/password.
			}
			break;

		case 2: // Case 2: Buyer.
		{
			buyer(); // Calling the buyer menu.
		}

		case 3: // Case 3: Exit.
		{
			exit(0); // Exits the program.
		}

		default: // If an invalid option is selected.
		{
			cout << "Please select from the given options";
		}

	}
	goto m; // Goes back to the beginning of the menu.
}

// Function for the administrator menu.
void shopping::administrator() 
{
	m:
	int choice; // Variable to store the administrator's choice.
	cout << "\n\n\n\t\t\t Administrator Menu";
	// Displaying the administrator menu options.
	cout << "\n\t\t\t|___1) Add the product_____|";
	cout << "\n\t\t\t|                          |";
	cout << "\n\t\t\t|___2) Edit the product____|";
	cout << "\n\t\t\t|                          |";
	cout << "\n\t\t\t|___3) Delete the product__|";
	cout << "\n\t\t\t|                          |";
	cout << "\n\t\t\t|___4) Back to main menu___|";

	cout << "\n\n\t Please enter your choice";
	cin >> choice; // Reading the administrator's choice.

	// Decisions based on the administrator's choice.
	switch (choice)
	{
		case 1:
			add(); // Calls function to add a product.
			break;

		case 2:
			edit(); // Calls function to edit a product.
			break;

		case 3:
			rem(); // Calls function to remove a product.
			break;

		case 4:
			menu(); // Goes back to the main menu.
			break;

		default:
			cout << "Invalid choice"; // If an invalid choice is made.
	}
	goto m;
}

// Function for the buyer menu.
void shopping::buyer()
{
	m:
	int choice; // Variable to store the buyer's choice.
	cout << "\t\t\t   Buyer \n";
	// Displaying the buyer menu options.
	cout << "_____________________\n";
	cout << "                     \n";
	cout << "\t\t\t1) Buy product \n";
	cout << "                     \n";
	cout << "\t\t\t2) Go back     \n";
	cout << "\t\t\t Enter your choice: ";
	cin >> choice; // Reading the buyer's choice.

	// Decisions based on the buyer's choice.
	switch (choice)
	{
	case 1:
		receipt(); // Calls function to generate a receipt.
		break;

	case 2:
		menu(); // Goes back to the main menu.
		break;
	
	default:
		cout << "Invalid choice!";
	}
	goto m;
}

// Function to add a new product.
void shopping::add()
{
	m:
	fstream data; // File stream object for file operations.

	int c;
	int token = 0;
	float p;
	float d;
	string n;

	// Variables to store new product details.
	cout << "\n\n\t\t\t Add new product";
	cout << "\n\n\t Add product code of the product";
	cin >> pcode; // Reading the product code.
	cout << "\n\n\t Name of the product";
	cin >> pname; // Reading the product name.
	cout << "\n\n\t Price of the product";
	cin >> price; // Reading the price.
	cout << "\n\n\t Discount on the product";
	cin >> dis; // Reading the discount.

	// Opens the file "database.txt" for reading.
	data.open("database.txt", ios::in);

	// Check if the file exists.
	if (!data)
	{
		// If the file does not exist, open it for writing.
		data.open("database.txt", ios::app|ios::out);
		// Writes the product data to the file.
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close(); // Closes the file.
	}
	// Else block for when the file 'database.txt' already exists.
	else
	{
		// c = variable to store product code from the file.
		// n = variable to store product name from the file.
		// p = variable to store product price from the file.
		// d = variable to store product discount from the file.
		
		// Reading the first set of product data from the file.
		data >> c >> n >> p >> d;

		// Loop to read the file until the end of file (eof) is reached.
		while (!data.eof())
		{
			// Checking if the current product code matches the new product code.
			if (c == pcode)
			{
				token++; // Incrementing the token if a match is found.
			}
			// Reading the next set of product data from the file.
			data >> c >> n >> p >> d;
		}
		data.close(); // Closing the file after reading all data.

		// Checking if the new product code already exists in the file. 
		if (token == 1)
		{
			goto m; // If the product code exists, go back to the label 'm'.
		}
		else
		{
			// If the product code does not exist, open the file to append the new product data.
			data.open("database.txt", ios::app | ios::out);
			// Writing the new product data to the file.
			data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			data.close(); // Closing the file after writing.
		}
	}
	cout << "\n\n\t\t Record inserted!"; // Message indicating that the record was inserted.
}

// Function to edit an existing product.
void shopping::edit()
{
	fstream data, data1; // Two file stream objects for reading and writing data.


	int pkey; // Product code of the product to be edited.
	int token = 0; // A flag to check if the product was found for editing.
	int c;
	float p;
	float d;
	string n;

	cout << "\n\t\t\t Edit the record!";
	cout << "\n\t\t\t Enter the product code: ";
	cin >> pkey; // Reading the product code to be edited.

	data.open("database.txt", ios::in); // Opening the file for reading.
	if (!data)
	{
		cout << "\n\n File does not exist!"; // If the file doesn't exist.
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out); // Opening a new file for writing.

		// Reading data from the original file.
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if (pkey == pcode)
			{
				// If the product code matches, ask for new details and write them to the new file.
				cout << "\n\t\t Enter the new product code: ";
				cin >> c;
				cout << "\n\t\t Product name: ";
				cin >> n;
				cout << "\n\t\t Enter the price: ";
				cin >> p;
				cout << "\n\t\t Enter the product discount: ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Record edited!";
				token++;
			}
			else
			{
				// If the product code doesn't match, write the original data to the new file.
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis; // Continue reading the next product.
		}
		data.close();
		data1.close();
		
		remove("database.txt"); // Remove the old file.
		rename("database1.txt","database.txt"); // Rename the new file to the original file name.

		if (token == 0)
		{
			cout << "\n\n Record not found sorry!"; // If no record was found to edit.
		}
	}
}

// Function to remove a product.
void shopping::rem()
{
	fstream data, data1; // Two file objects for reading and writing data.

	int pkey; // Product code of the product to delete.
	int token = 0; // A flag to check if the product was found for deletion.
	cout << "\n\n\t Delete product";
	cout << "\n\n\t Enter the product code: ";
	cin >> pkey; // Reading the product code to be deleted.
	
	data.open("database.txt", ios::in);  // Opening the file for reading.
	if (!data)
	{
		cout << "File does not exist!"; // If the file doesn't exist.
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out); // Opening a new file for writing.
		
		// Reading data from the original file.
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if (pcode == pkey)
			{
				cout << "\n\n\t Product deleted successfully";
				token++; // Indicate that a product was deleted.
			}
			else
			{
				// If the product code doesn't match, write the data to the new file.
				data1 << " " << pcode << " " << pname << " " << price << " " << dis<<"\n";
			}
			data >> pcode >> pname >> price >> dis; // Continue reading the next product.
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "\n\n Record not found sorry!"; // If no record was found to delete.
		}
	}
}

// Function to list all products.
void shopping::list()
{
	fstream data; // File object for reading data.

	data.open("database.txt", ios::in); // Opening the file for reading.
	cout << "\n\n|________________________________________________________________\n";
	cout << "ProNo\t\tName\t\tPrice\n"; // Header for the product list.
	cout << "\n\n|________________________________________________________________\n";
	
	// Reading and displaying each product's details.
	data >> pcode >> pname >> price >> dis;
	while (!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price<<"\n"; // Displaying product details.
		data >> pcode >> pname >> price >> dis; // Continue reading the next product.
	}
	data.close(); // Closing the file after reading all products.
}

// Function to generate a receipt.
void shopping::receipt()
{
	fstream data; // File object for reading data.

	int arrc[100]; // Array to store product codes.
	int arrq[100]; // Array to store product quantities.
	char choice; // Variable for the user's choice.
	int c = 0; // Counter for the number of products.
	float amount = 0; // Total amount.
	float dis = 0; // Total discount.
	float total = 0; // Total price after discount.

	cout << "\n\n\t\t\t\t RECEIPT"; // Receipt header.
	data.open("database.txt", ios::in); // Opening the file for reading.
	if (!data)
	{
		cout << "\n\n Empty database!"; // If the database is empty.
	}
	else
	{
		data.close(); // Closing the file as it's only being checked for emptiness here.

		list(); // Displaying the list of available products.
		cout << "\n_______________________________________\n";
		cout << "\n|                                      \n";
		cout << "\n        Please place the order         \n";
		cout << "\n|                                      \n";
		cout << "\n_______________________________________\n";
		
		// Loop to allow the user to enter multiple products and quantities.
		do
		{
			m:
			cout << "\n\n Enter the product code: ";
			cin >> arrc[c]; // Reading the product code.
			cout << "\n\n Enter the product quantity: ";
			cin >> arrq[c]; // Reading the product quantity.
			
			// Check for duplicate product codes.
			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please try again!";
					goto m; // If duplicate, go back to product code entry.
				}
			}
			c++; // Incrementing the product count.
			cout << "\n\n Do you want to purchase another product? If yes or no then press (y / n).";
			cin >> choice; // Reading the user's choice to continue or stop.
		} while (choice == 'y');

		cout << "\n\n\t\t\t__________________________RECEIPT_______________________\n";
		cout << "\n Product No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";

		// Loop to calculate and print details for each chosen product.
		for (int i = 0; i < c; i++)
		{
			// Opening the database file to read product details.
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis; // Reading product details.
			while (!data.eof())
			{
				if(pcode==arrc[i]) // If the product code matches the chosen product.
				{
					amount = price * arrq[i]; // Calculating amount before discount.
					dis = amount - (amount * dis / 100); // Calculating discounted amount.
					total = total + dis; // Adding to the total purchase amount.
					// Printing the product details on the receipt.
					cout << "\n"<<"\t\t"<<pcode <<"\t\t"<< pname << "\t\t"<<arrq[i] <<"\t\t"<< price <<"\t\t"<< amount <<"\t\t"<< dis;
				}
				data >> pcode >> pname >> price >> dis; // Reading the next product.
			}
		}
		data.close(); // Closing the file after processing each product.

	}
	cout << "\n\n________________________________________________";
	cout << "\n Total Amount: "<<total; // Printing the total amount of the purchase.

}
int main()
{
	shopping s;
	s.menu();
}
