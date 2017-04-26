class Issue{

  Issue();
  Issue(Date issue_date, Date due_date, float fine, Book book, User user);
  Issue(const Issue &original);
  
  Date getIssueDate();
  void setIssueDate(Date issue_date);
  Date getDueDate();
  void setDueDate(Date due_date);
  float getFine();
  void setFine(float fine);
  Book getBook();
  void setBook(Book book);
  User getUser();
  void setUser(User user);

}
