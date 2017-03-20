# Central-Library-Management-IITB

The ultimate aim of this project is to implement an efficient Library Management System.



# Implementation
# Classes

1. BookDatabase  
  - "Ordered_map" is used as a data structure while loading the database based on
    the book_ids (Time Complexity = O(logn))
  - "Unordered_map" is used as supplementary data structures in various other types
    of searches like by author, publisher etc. (Time  Complexity = O(1) just for
    the sake of look up)
