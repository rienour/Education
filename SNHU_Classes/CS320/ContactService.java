package contact_service;

import java.util.ArrayList;
import java.util.NoSuchElementException;

/**
 * This class serves to provide an in-memory representation
 * for the system contact service.
 * 
 * @author rileyeichenou_snhu
 */
public class ContactService {
    // Private Class Members
    private ArrayList < Contact > contacts;

    // Constructor
    public ContactService() {
        contacts = new ArrayList < Contact > ();
    }

    /**
     * This helper function will search for a contact within the list of
     * contacts in the service instance
     * 
     * @param id string for the contact to search for
     * @return contact if found, null otherwise
     */
    private Contact findContactById(String id) {
        // Iterate through he contacts to find the contact
        for (Contact checkContact : this.contacts) {
            if (checkContact.getId() == id) {
                return checkContact;
            }
        }

        // The contact was not found
        return null;
    }

    /**
     * This function will handle adding a Contact to the instance
     * 
     * @param id string id for the contact to insert
     * @param firstName string id for the contact to insert
     * @param lastName string id for the contact to insert
     * @param phone string id for the contact to insert
     * @param address string id for the contact to insert
     */
    public void addContact(String id, String firstName, String lastName, String phone, String address) {
        Contact existingContact = this.findContactById(id);
        if (existingContact == null) {
            this.contacts.add(new Contact(id, firstName, lastName, phone, address));
        } else {
            throw new IllegalArgumentException("Contact with id " + id + " already exists.");
        }
    }

    /**
     * This function will handle deleting a Contact from the instance
     * 
     * @param id for the contact to delete
     */
    public void deleteContact(String id) {
        Contact targetContact = this.findContactById(id);
        if (targetContact == null) {
            throw new NoSuchElementException("Contact with id " + id + " does not exist.");
        } else {
            this.contacts.remove(targetContact);
        }
    }

    /**
     * This function will handle updating firstName on the Contact with the id, if
     * it exists.
     * 
     * @param id string for the contact to update
     * @param firstName new value to update on the contact
     */
    public void updateContactFirstName(String id, String firstName) {
        Contact targetContact = this.findContactById(id);
        if (targetContact == null) {
            throw new NoSuchElementException("Contact with id " + id + " does not exist.");
        } else {
            targetContact.setFirstName(firstName);
        }
    }

    /**
     * This function will handle updating lastName on the Contact with the id,
     * if it exists.
     * 
     * @param id string for the contact to update
     * @param lastName new value to update on the contact
     */
    public void updateContactLastName(String id, String lastName) {
        Contact targetContact = this.findContactById(id);
        if (targetContact == null) {
            throw new NoSuchElementException("Contact with id " + id + " does not exist.");
        } else {
            targetContact.setLastName(lastName);
        }
    }

    /**
     * This function will handle updating phone on the Contact with the id, if
     * it exists.
     * 
     * @param id string for the contact to update
     * @param phone new value to update on the contact
     */
    public void updateContactPhone(String id, String phone) {
        Contact targetContact = this.findContactById(id);
        if (targetContact == null) {
            throw new NoSuchElementException("Contact with id " + id + " does not exist.");
        } else {
            targetContact.setPhone(phone);
        }
    }

    /**
     * This function will handle updating address on the Contact with the id, 
     * if it exists.
     * 
     * @param id string for the contact to update
     * @param address new value to update on the contact
     */
    public void updateContactAddress(String id, String address) {
        Contact targetContact = this.findContactById(id);
        if (targetContact == null) {
            throw new NoSuchElementException("Contact with id " + id + " does not exist.");
        } else {
            targetContact.setAddress(address);
        }

    }
};
