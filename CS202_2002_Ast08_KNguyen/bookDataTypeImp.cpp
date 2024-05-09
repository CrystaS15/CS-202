/* Name: Kristy Nguyen, NSHE ID #5006243601, CS 202-1002, Assignment 8
 * Description: bookDataType implementation file
 // Provide functionality for reading and storing book information */


#include "bookDataType.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

/* constructor_identifier: set class variable defaults
 * parameters: none
 * return type: none */
bookDataType::bookDataType()
{
  // set books file name to empty string
  booksFileName = "";

  // set bookCount to 0
  bookCount = 0;

  // set topBooksLimit to default value of 5
  topBooksLimit = 5;

  // set book info error struct counts to 0
  bookErrInfo.bookIDErrors = 0;
  bookErrInfo.bookYearErrors = 0;
  bookErrInfo.AveRatingErrors = 0;
  bookErrInfo.duplicateDataErrors = 0;

  // set web page file name to default value of "index.html"
  webPageFileName = "index.html";

  // set exceptions file to default value of "errors.txt"
  exceptionsFileName = "errors.txt";

  // set pointers to nullptr
  topBooks = nullptr;
  bookInfo = nullptr;
}

/* deconstructor_identifier: delete dynamically allocated arrays and
    set class variables to default values
 * parameters: none
 * return type: none */
bookDataType::~bookDataType()
{
  // delete dynamically allocated arrays
  delete [] topBooks;
  delete [] bookInfo;

  // set pointers to nullptr
  topBooks = nullptr;
  bookInfo = nullptr;

  // set books file name to empty string
  booksFileName = "";

  // set bookCount to 0
  bookCount = 0;

  // set topBooksLimit to default value of 5
  topBooksLimit = 5;

  // set book info error struct counts to 0
  bookErrInfo.bookIDErrors = 0;
  bookErrInfo.bookYearErrors = 0;
  bookErrInfo.AveRatingErrors = 0;
  bookErrInfo.duplicateDataErrors = 0;

  // set web page file name to default value of "index.html"
  webPageFileName = "index.html";

  // set exceptions file to default value of "errors.txt"
  exceptionsFileName = "errors.txt";
}

/* function_identifier: read command line qualifiers to
      obtain file name and set extra information flag (t/f)
 * parameters: argument count, argument vector, fileName (string), showFlag (bool)
 * return type: t/f (bool) */
bool bookDataType::getBookArguments(int argc, char * argv[], string& fileName, bool& showFlag)
{
  // default value of showFlag should be false
  showFlag = false;

  // Error for incorrect usage of argument command line
  if (argc < 3){
    cout << "Usage: ./books -i <bookDataFileName> [<-show|-noshow>]" << endl;
    return false;
  }

  // loop through argument command line
  for (int i = 1; i < argc-1; i++) {

    // store file name
    if (string(argv[i]) == "-i") {
      fileName = argv[i+1];
    }

  }

  // Error for no "-i"
  if (string(argv[1]) != "-i" && string(argv[2]) != "-i") {
    cout << "Error, invalid input file name specifier." << endl;
  }

  // Error for if the file name length is less than 5
  if (fileName.length() < 5) {
    // cout << "Error, invalid input file name specifier." << endl;
    return false;
  }

  // Error for if the file name does not have csv extension
  if (fileName.find(".csv") == string::npos) {
    cout << "Error, book data file name must be '.csv' extension." << endl;
    return false;
  }


  // Error for if the file does not exist
  if (access(fileName.c_str(), F_OK) == -1) {
    cout << "setFileName: Error, file does not exist." << endl;
    return false;
  }

  // Errors that occur only if the argument count is greater than 3
  if (argc > 3) {

    // Error for invalid command line options
    for (int i = 1; i <= argc - 1; i++) {
      if (argv[i] == string("-")) {
        cout << "Error, invalid command line options." << endl;
        return false;
      }
    }

    // Set showFlag to true if "-show" is specified
    if (argv[1] == string("-show") || argv[3] == string("-show")) {
      showFlag = true;
    }

    // Set showFlag to false if "-noshow" is specified
    else if (argv[1] == string("-noshow") || argv[3] == string("-noshow")) {
      showFlag = false;
    }

    // Error for show extra flag
    else {
      cout << "Error, invalid show extra information specifier." << endl;
      return false;
    }

  }

  return true;
}

/* function_identifier: return booksFileName
 * parameters: none
 * return type: booksFileName (string) */
string bookDataType::getBookFileName() const
{
  return booksFileName;
}

/* function_identifier: return webPageFileName
 * parameters: none
 * return type: webPageFileName (string) */
string bookDataType::getWebPageFileName() const
{
  return webPageFileName;
}

/* function_identifier: set webPageFileName to passed in fileName
 * parameters: fileName (string)
 * return type: none */
void bookDataType::setWebPageFileName(const string fileName)
{

  // File name must be minimum length of 6
  if (fileName.length() < 6) {
    return;
  }

  // File name must have ".html" extension
  if (fileName.find(".html") == string::npos) {
    return;
  }

  webPageFileName = fileName;

  return;
}

/* function_identifier: return exceptionsFileName
 * parameters: none
 * return type: exceptionsFileName (string) */
string bookDataType::getExceptionsFileName() const
{
  return exceptionsFileName;
}

/* function_identifier: set exceptionsFileName to passed in file name
 * parameters: fileName (string)
 * return type: none */
void bookDataType::setExceptionsFileName(const string fileName)
{

  // File name must be minimum length of 5
  if (fileName.length() < 5) {
    return;
  }

  // File name must have ".txt" extension
  if (fileName.find(".txt") == string::npos) {
    return;
  }

  exceptionsFileName = fileName;

  return;
}

/* function_identifier: return bookIDErrors from bookErrsStruct
 * parameters: none
 * return type: bookIDErrors (unsigned int) */
unsigned int bookDataType::getReadBookIDErrors() const
{
  return bookErrInfo.bookIDErrors;
}

/* function_identifier: return bookYearErrors from bookErrsStruct
 * parameters: none
 * return type: bookYearErrors (unsigned int) */
unsigned int bookDataType::getReadBookYearErrors() const
{
  return bookErrInfo.bookYearErrors;
}

/* function_identifier: return bookAveRatingErrors from bookErrsStruct
 * parameters: none
 * return type: bookAveRatingErrors (unsigned int) */
unsigned int bookDataType::getReadBookAveRatingErrors() const
{
  return bookErrInfo.AveRatingErrors;
}

/* function_identifier: return duplicateDataErrors from bookErrsStruct
 * parameters: none
 * return type: duplicateDataErrors (unsigned int) */
unsigned int bookDataType::getReadBookDuplicateErrors() const
{
  return bookErrInfo.duplicateDataErrors;
}

/* function_identifier: return topBooksLimit
 * parameters: none
 * return type: topBooksLimit (unsigned int) */
unsigned int bookDataType::getTopBooksLimits() const
{
  return topBooksLimit;
}

/* function_identifier:
 * parameters:
 * return type:  */
void bookDataType::setTopBooksLimit(unsigned int )
{



  return;
}

/* function_identifier: return bookCount
 * parameters: none
 * return type: bookCount (unsigned int) */
unsigned int bookDataType::getBookCount() const
{
  return bookCount;
}

/* function_identifier:
 * parameters:
 * return type:  */
float bookDataType::getAverageOverallRating() const
{


  return 0.0;
}

/* function_identifier: display the formatted book information
 * parameters: index number for bookInfo struct array
 * return type: none */
void bookDataType::showBookData(unsigned int indexNum) const
{

  cout << "Book Information:" << endl;
  cout << "  " << "Title:    " << bookInfo[indexNum].bookTitle << endl;
  cout << "  " << "Book ID   " << bookInfo[indexNum].bookID << endl;
  cout << "  " << "ISBD:     " << bookInfo[indexNum].isbn << endl;
  cout << "  " << "Year:     " << bookInfo[indexNum].pubYear << endl;
  cout << "  " << "Ave Rate: " << bookInfo[indexNum].aveRating << endl;
  cout << endl;

  return;
}

/* function_identifier:
 * parameters:
 * return type:  */
void bookDataType::showHighestRatedBooks() const
{



  return;
}

/* function_identifier:
 * parameters:
 * return type:  */
bool bookDataType::readBookData(const string /* fileName */)
{

  /* ifstream inFile;
  string csvLine = "";
  string csvFields[COL_LIMIT] = {0};

  inFile.open(fileName);

  if (inFile.is_open() == false) {
    cout << "Error, file named " << fileName;
    cout << " is unable to open." << endl;
    return false;
  }

  // skip first line of data file
  inFile.ignore(10000, '\n'); */

  /* while (!inFile.eof()) {

    // read in line to a string
    getline(inFile, csvLine);

    // ignore blank lines
    if (csvLine == "") {
      inFile.ignore(10000, '\n');
    }

    // accept string in csv format and break into 23 fields
    parseLine(csvLine, csvFields);

    // ...

  } */

  return true;
}

/* function_identifier:
 * parameters:
 * return type:  */
void bookDataType::findHighestRatedBooks()
{
  // float maxNum = bookInfo[0].aveRating;

  topBooks = new unsigned int[topBooksLimit];

  return;
}

/* function_identifier:
 * parameters:
 * return type:  */
void bookDataType::parseLine(string /* bookLine */, string /* bookFields */[]) const
{

  // int commaPosition;
  // int quotePosition;
  // int doubleQuotePosition;

  // for (int i = 0; i < COL_LIMIT; i++) {

  //     commaPosition = bookLine.find(",");
  //     quotePosition = bookLine.find("\"");

  //     doubleQuotePosition = bookLine.find("\"\"");
  //     while (doubleQuotePosition != string::npos) {
  //       bookLine = bookLine.replace(doubleQuotePosition, 2, "\"");
  //       doubleQuotePosition = bookLine.find("\"\"");
  //     }

  //     commaPosition = bookLine.find(",");
  //     quotePosition = bookLine.find("\"");
  //     if (commaPosition+1 == quotePosition) {
  //       bookFields[i] = bookLine.substr(0, bookLine.find(",\""));
  //       bookLine = bookLine.substr(commaPosition+1);
  //     }

  //     else { // comma without quote after it

  //       commaPosition = bookLine.find(",");
  //       bookFields[i] = bookLine.substr(0, commaPosition - 0);
  //       bookLine = bookLine.substr(commaPosition+1);
  //     }

  //   }


  return;
}
