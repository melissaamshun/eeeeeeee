

#include "person.h"

Person::Person() {
  // I'm already done!
  set_person();
}

Person::~Person() {
  delete birthdate;
  // TODO: complete the method!
  delete email;
  delete phone;
}

Person::Person(string f_name, string l_name, string b_date, string email_addr,
               string phone_nbr) {
  // TODO: Complete this method!
  // phone and email strings are in full version
  this->f_name = f_name;
  this->l_name = l_name;
  birthdate = new Date(b_date);
  int finder = email_addr.find(")");
  string email_typ = email_addr.substr(1, finder - 1);
  string addr = email_addr.substr(finder + 2);
  finder = phone_nbr.find(")");
  string phone_typ = phone_nbr.substr(1, finder - 1);
  string nbr = phone_nbr.substr(finder + 2);
  email = new Email(email_typ, addr);
  //&email = *Email(email_typ, addr);
  // email = &Email(email_typ, addr);
  phone = new Phone(phone_typ, nbr);
}

Person::Person(string filename) { set_person(filename); }

void Person::set_person() {
  // prompts for the information of the user from the terminal
  // first/last name can have spaces!
  // date format must be "M/D/YYYY"
  // We are sure user enters info in correct format.
  // TODO: complete this method!

  string temp;
  string type;

  std::cout << "First Name: ";
  // pay attention to how we read first name, as it can have spaces!
  std::getline(std::cin, f_name);

  std::cout << "Last Name: ";
  std::getline(std::cin, l_name);

  std::cout << "Birthdate (M/D/YYYY): ";
  std::getline(std::cin, temp);
  // pay attention to how we passed argument to the constructor of a new object
  // created dynamically using new command
  birthdate = new Date(temp);

  std::cout << "Type of email address: ";
  // code here
  std::getline(std::cin, type);
  std::cout << "Email address: ";
  // code here
  string emailAddr;
  std::getline(std::cin, emailAddr);
  email = new Email(type, emailAddr);
  std::cout << "Type of phone number: ";
  // code here
  std::getline(std::cin, type);
  std::cout << "Phone number: ";
  // code here
  string phoneNum;
  std::getline(std::cin, phoneNum);
  phone = new Phone(type, phoneNum);
}

void Person::set_person(string filename) {
  // reads a Person from a file
  // Look at person_template files as examples.
  // Phone number in files can have '-' or not.
  // TODO: Complete this method!
  //string fn, ln, bd, l4, l5;
  ifstream fin;
  fin.open(filename.c_str());
  /*
  std::getline(fin, fn);
  std::getline(fin, ln);
  std::getline(fin, bd);
  std::getline(fin, l4);
  std::getline(fin, l5);
  this->f_name = fn;
  // cout << "DB: "<< f_name << endl;
  this->l_name = ln;
  // cout << "DB: "<< l_name << endl;
  birthdate = new Date(bd);
  // from https://www.w3schools.blog/c-check-if-string-contains-substring

  string email_addr, phone_nbr;
  if (l4.find('@') != string::npos) {
    email_addr = l4;
    phone_nbr = l5;

  } else {
    email_addr = l5;
    phone_nbr = l4;

  }

  int finder = email_addr.find(")");
  string email_typ = email_addr.substr(1, finder - 1);
  string addr = email_addr.substr(finder + 2);
  finder = phone_nbr.find(")");
  string phone_typ = phone_nbr.substr(1, finder - 1);
  string nbr = phone_nbr.substr(finder + 2);
  // cout << "DB: "<< phone_nbr;
  email = new Email(email_typ, addr);
  phone = new Phone(phone_typ, nbr);
*/

  string line;
  int cnt = 0;
  string fn, ln, bd, email_addr, phone_nbr;

  while (getline(fin, line)) {
    cnt++;
    switch (cnt) {
    case 1:
      fn = line;
      break;
    case 2:
      ln = line;
      break;
    case 3:
      bd = line;
      break;
    case 4:
      if (line.find("@") != string::npos) {
        email_addr = line;
      } else {
        phone_nbr = line;
      }
      break;
    case 5:
      if (line.find("@") != string::npos) {
        email_addr = line;
      } else {
        phone_nbr = line;
      }
      break;
    }
  }
    this->f_name = fn;
    this->l_name = ln;
    //cout << this->l_name << endl;
    birthdate = new Date(bd);

    int finder = email_addr.find(")");
    string email_typ = email_addr.substr(1, finder - 1);
    string addr = email_addr.substr(finder + 2);
    email = new Email(email_typ, addr);
    
    finder = phone_nbr.find(")");
    string phone_typ = phone_nbr.substr(1, finder - 1);
    string nbr = phone_nbr.substr(finder + 2);
    phone = new Phone(phone_typ, nbr);
    cout << "DB: ";
    phone->print();

    fin.close();
  }


  
  
bool Person::operator==(const Person &rhs) {
  // TODO: Complete this method!
  // Note: you should check first name, last name and birthday between two
  // persons refer to bool Date::operator==(const Date& rhs)

  string rhs_name = rhs.get_name();
  if ((rhs_name == this->get_name()) &&
      (*(rhs.get_birthdate()) == *(this->birthdate))) {
    return true;
  }
  return false;
}

bool Person::operator!=(const Person &rhs) {
  // TODO: Complete this method!
  return !(*this == rhs);
}

void Person::print_person() {
  // Already implemented for you! Do not change!
  cout << "DB: " + l_name << endl;
  cout << l_name << ", " << f_name << endl;
  birthdate->print_date("Month D, YYYY");
  email->print();
  phone->print();
}

string Person::get_name() const {
  string fullName = l_name + ", " + f_name;
  return fullName;
}

string Person::get_lname() { return l_name; }

Date *Person::get_birthdate() const { return birthdate; }
