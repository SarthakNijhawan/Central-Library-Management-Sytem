class Claim{

  Claim();
  Claim(Date claim_date, Date expiry_date, Book book, User user);
  Claim(const Claim &original);
  
  Date getClaimDate();
  void setClaimDate(Date claim_date);
  Date getExpiryDate();
  void setExpiryDate(Date expiry_date);
  Book getBook();
  void setBook(Book book);
  User getUser();
  void setUser(User user);

}
