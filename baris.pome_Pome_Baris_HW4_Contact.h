//
// Created by Barış Pome on 22.05.2024.
//

#ifndef BARIS_POME_POME_BARIS_HW4_CONTACT_H
#define BARIS_POME_POME_BARIS_HW4_CONTACT_H

#include <string>
#include <iostream>

using namespace std;



// The Contact class represents a contact with a name, surname, phone number, and city
class Contact {
public:

    // Constructor
    Contact() = default;

    Contact(const string& name, const string& surname, const string& number, const string& city) // Constructor with parameters
            : name(name), surname(surname), number(number), city(city) {}


    // Comparison operators

    // Comparison operators are implemented to compare contacts based on in the following order: name, surname, number

    bool operator<(const Contact& c) const {
        if (name != c.name)
            return name < c.name;
        else if (surname != c.surname)
            return surname < c.surname;
        else
            return number < c.number;
    }

    // Comparison operators are implemented to compare contacts based on in the following order: name, surname, number

    bool operator<=(const Contact& c) const {
        return (*this < c) || (*this == c);
    }

    bool operator>(const Contact& c) const {
        return !(*this <= c);
    }

    bool operator==(const Contact& c) const {
        return name == c.name && surname == c.surname && number == c.number;
    }

    bool operator==(const string& str) const {
        string full_name = name + " " + surname;
        if (full_name.find(str) == 0) {
            return true;
        }
        return false;
    }

    bool operator<(const string& str) const {
        string full_name = name + " " + surname;
        return full_name < str;
    }

    bool operator>(const string& str) const {
        string full_name = name + " " + surname;
        return full_name > str;
    }

    bool operator>=(const Contact& c) const {
        return (*this > c) || (*this == c);
    }

    void print() { // Print the contact information
        cout << name << " " << surname << " " << number << " " << city << endl;
    }

private:
    // Data members
    string name;
    string surname;
    string number;
    string city;
};

#endif //BARIS_POME_POME_BARIS_HW4_CONTACT_H
