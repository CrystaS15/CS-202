#ifndef BOOK_DATA_TYPE_H
#define BOOK_DATA_TYPE_H

/* Name: Kristy Nguyen, NSHE ID #5006243601, CS 202-1002, Assignment 8
 * Description: bookDataType header file
 // Provide functionality for reading and storing book information */

#include <string>

using namespace std;

class bookDataType 
{
  private:
    
    static constexpr unsigned int COL_LIMIT = 23;
    static constexpr unsigned int TOP_LIMIT = 20;
    // variables defined for column and top limit

    string booksFileName;
    string webPageFileName;
    string exceptionsFileName;
    unsigned int bookCount;
    unsigned int topBooksLimit;
    unsigned int *topBooks;
    // variables defined for book info

    struct bookErrsStruct
    {
      unsigned int bookIDErrors;
      unsigned int bookYearErrors;
      unsigned int AveRatingErrors;
      unsigned int duplicateDataErrors;
    };
    bookErrsStruct bookErrInfo;
    // define struct for book errors

    struct bookStruct
    {
      string bookTitle;
      string isbn;
      short pubYear;
      float aveRating;
      string imageURL;
      unsigned int bookID;
    };
    bookStruct *bookInfo;
    // struct for book info

  public:
    
    bookDataType();
    // set default values for book data

    ~bookDataType();
    // delete dynamically allocated arrays and set default values for book data

    bool getBookArguments(int, char *[], string &, bool &);
    // read command line qualifiers to obtain file name and set extra information flag (t/f)

    string getBookFileName() const;
    // return booksFileName

    /* OPTIONAL PRIVATE FUNCTION
    void setBookFileName(const string);
    // sets booksFileName to passed fileName...
    */

    string getWebPageFileName() const;
    void setWebPageFileName(const string);
    // return webPageFileName
    // set webPageFileName to passed fileName...

    string getExceptionsFileName() const;
    void setExceptionsFileName(const string);
    // return exceptionsFileName
    // set exceptionsFileName to passed fileName...

    unsigned int getReadBookIDErrors() const;
    unsigned int getReadBookYearErrors() const;
    unsigned int getReadBookAveRatingErrors() const;
    unsigned int getReadBookDuplicateErrors() const;
    // return applicable structure field from bookErrorsStruct
    
    unsigned int getTopBooksLimits() const;
    void setTopBooksLimit(unsigned int);
    // return topBooksLimit
    // set topBooksLimit to current number of highest rated books to be found

    unsigned int getBookCount() const;
    // return bookCount
    
    float getAverageOverallRating() const;
    // return overall average of book rating in entire current data set

    void showBookData(unsigned int) const;
    // display formatted book info to screen in specified format

    void showHighestRatedBooks() const;
    // show topBooksLimit number of highest rated books...
    
    bool readBookData(const string);
    // read books file (CSV)...

    /* EXTRA CREDIT FUNCTION
    bool buildWebPage(const string="CS 202 Top Books") const;
    // build HTML web page...
    */

    void findHighestRatedBooks();
    // find topBooksLimit number of highest rated books...

    void parseLine(string, string []) const;
    // accept string in comma-separated format...

};

#endif