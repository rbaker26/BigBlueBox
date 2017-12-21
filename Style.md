# Style and Coding Standards

This project follows the standard C++ styling with strict adherence to Doxygen style comments.
<br> <br>

## C++ Standards
The following uses some of google's C++ style guide.
<br>

### Headers
 * All .cpp files should also have a .h file.  The header should contain the declaration and the .cpp should have the implementation.
 * Headers should be self-contained and single purpose.
 * All headers must start with #ifndef, #define and end with #endif to prevent errors.
 * Do not use "using namespace ..." or "using ..." as it bloats the header file.
<br>

### Classes
 * Write out both the default constructor and destructor.
 * Use inheritance sparingly. Composition adds more to readability.
 * Avoid multiple inheritance.
 * Only overload operators if it makes sense.
 * Make all variables private or protected unless absolutely necessary.
<br>

### Functions
 * Give functions discriptive names.
 * If a function is not a mutator, declare it const.
 * Function parameters should be declared in logical order.
 * Comment any part of a function that took you more that 15 seconds to think of.
 <br>
 
### Misc.
 * Use smart pointers.
 * Use auto sparingly.
 * Use pass-by-reference or const-pass-by-reference when passing objects.
<br>

All standard C++ code should be written cleanly, using proper tabing and spacing.
Below is an example

```cpp
  //...
  bool myBool = ( (a < b && c >= d) ||
                  (c < d && a == b) );
  if(myBool) 
  {
       myFunction(a, b);
  } 
  else
  {
       otherFunction(c, d);
  } // end if-else
  //...
```

## Doxygen Commenting

All Doxygen comments should be in the .h files with the declarations and prototypes.

### Example Class with Doxygen

```cpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS   // note, this is here so Doxygen doesn't read Style.md
#ifndef _REGEX_H
#define _REGEX_H
//*********************************************************************************
// For Regex matching
// Do not use <QRegex>, it is outdated.
#include <QRegularExpression>

// For strings
#include <QString>
//*********************************************************************************


//*********************************************************************************
//! \class   _Regex
//! \brief   Regex String Validation Class
//! \details No objects may be instantiated.  ALl methods are static.
//! \author  Bob Baker
//*********************************************************************************
class _Regex
{
public:
    //**********************************************************
    //! \brief   Contains requirements for Item names.
    //! \details Static:
    //! \param   QString itemName
    //! \return  bool isValidItemName
    //! \author  Bob Baker
    static bool isItemName(QString itemName);
    //**********************************************************

    //**********************************************************
    //! \brief   Contains requirements for box names.
    //! \details Static:
    //! \param   QString boxName
    //! \return  bool isValidBoxName
    //! \author  Bob Baker
    static bool isBoxName(QString boxName);
    //**********************************************************
private:
    //**********************************************************
    //! \brief   Default no-args constructor
    //! \details Private: No objects can be instantiated.
    //! \author  Bob Baker
    _Regex();
    //**********************************************************
};
//*********************************************************************************

#endif // _REGEX_H
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
```



