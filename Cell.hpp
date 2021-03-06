/**
 * \mainpage COMP2012H Programming Assignment 1, Fall 2014
 *
 * \author SUN Yushi
 * \author 20176087
 * \author jeffsun@jowos.moe
 * \author LA1
 *
 * \date Sept. 24 2014
 *
 * Instructor: <a href="http://www.cs.ust.hk/~dekai/">Dekai Wu</a>
 * Due: 2014.09.26 at 23:00 by CASS
 * <p><strong style="color:red">
 *   Remarks: I defined an error handler helper function, implemented a copy constructor and realized proper destruction.
 * </strong></p>
 */

/**
 * \file Cell.hpp
 *
 * Encapsulates the abstract interface for a concrete class-based
 * implementation of cells for a cons list data structure.
 */

#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

//my own error handler :-)
#include "error.hpp"

class Cell;

/**
 * \struct ConsPair
 * \brief contains one car pointer one cdr pointer
 */
struct ConsPair {
  Cell* car_m;
  Cell* cdr_m;
};

/**
 * \class Cell
 * \brief Class Cell
 */
class Cell {
public:

  /**
   * \brief Constructor to make int cell.
   */
  Cell(const int i);

  /**
   * \brief Constructor to make double cell.
   */
  Cell(const double d);

  /**
   * \brief Constructor to make symbol cell.
   */
  Cell(const char* const s);

  /**
   * \brief Constructor to make cons cell.
   */
  Cell(Cell* const my_car, Cell* const my_cdr);

  /**
   * \brief Copy constructor
   */
  Cell(const Cell& c);

  /**
   * \brief Check if this is an int cell.
   * \return True iff this is an int cell.
   */
  bool is_int() const;

  /**
   * \brief Check if this is a double cell.
   * \return True iff this is a double cell.
   */
  bool is_double() const;

  /**
   * \brief Check if this is a symbol cell.
   * \return True iff this is a symbol cell.
   */
  bool is_symbol() const;

  /**
   * \brief Check if this is a cons cell.
   * \return True iff this is a cons cell.
   */
  bool is_cons() const;

  /**
   * \brief Accessor (error if this is not an int cell).
   * \return The value in this int cell.
   */
  int get_int() const;

  /**
   * \brief Accessor (error if this is not a double cell).
   * \return The value in this double cell.
   */
  double get_double() const;

  /**
   * \brief Accessor (error if this is not a symbol cell).
   * \return The symbol name in this symbol cell.
   */
  std::string get_symbol() const;

  /**
   * \brief Accessor (error if this is not a cons cell).
   * \return First child cell.
   */
  Cell* get_car() const;

  /**
   * \brief Accessor (error if this is not a cons cell).
   * \return Rest child cell.
   */
  Cell* get_cdr() const;

  /**
   * \brief Print the subtree rooted at this cell, in s-expression notation.
   * \param os The output stream to print to.
   */
  void print(std::ostream& os = std::cout) const;
  
  /**
   * \brief Convert a value cell to string.
   * \return The string value
   */
  std::string to_string() const;

  /**
   * \brief Destructor
   */
  ~Cell();

private:
  enum TypeTag {type_int, type_double, type_symbol, type_conspair};
  TypeTag tag_m;
  
  union {
    int int_m;
    double double_m; 
    char* symbol_m;
    ConsPair conspair_m;
  };
};

// Reminder: cons.hpp expects nil to be defined somewhere (for this
// implementation, Cell.cpp is the logical place to define it).
// Here we promise this again, just to be safe.
extern Cell* const nil;

#endif // CELL_HPP
