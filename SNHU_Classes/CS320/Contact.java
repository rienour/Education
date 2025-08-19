package contact_service;

/**
 * This class serves to provide an in-memory representation
 * for the system contacts.
 * 
 * Mutating the contact data will be limited to services within the package
 * 
 * @author rileyeichenou_snhu
 */
public class Contact {
    // Private Class Members
    private final String id;
    private String firstName;
    private String lastName;
    private String phone;
    private String address;

    // Public Class Members
    public static final int MAX_ID_LENGTH = 10;
    public static final int MAX_FIRST_NAME_LENGTH = 10;
    public static final int MAX_LAST_NAME_LENGTH = 10;
    public static final int MAX_ADDRESS_LENGTH = 30;
    public static final int REQUIRED_PHONE_LENGTH = 10;

    // Constructor
    public Contact(String id, String firstName, String lastName, String phone, String address) {
        if (isIdValid(id)) {
            throw new IllegalArgumentException("Invalid id.");
        }

        if (isFirstNameValid(firstName)) {
            throw new IllegalArgumentException("Invalid first name.");
        }

        if (isLastNameValid(lastName)) {
            throw new IllegalArgumentException("Invalid last name.");
        }

        if (isPhoneValid(phone)) {
            throw new IllegalArgumentException("Invalid phone.");
        }

        if (isAddressValid(address)) {
            throw new IllegalArgumentException("Invalid address.");
        }

        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.phone = phone;
        this.address = address;
    }

    /** Private Class Methods **/
    /**
     * This function verifies the id is valid.
     * 
     * A valid ID is:
     *   - Non-null
     *   - No more than 10 characters
     * @param id String value to check
     */
    private static boolean isIdValid(String id) {
        return id != null && id.length() <= MAX_ID_LENGTH;
    }

    /**
     * This function verifies the first name is valid.
     * 
     * A valid first name is:
     *   - Non-null
     *   - No more than 10 characters
     * @param firstName String value to check
     */
    private static boolean isFirstNameValid(String firstName) {
        return firstName != null && firstName.length() <= MAX_FIRST_NAME_LENGTH;
    }

    /**
     * This function verifies the last name is valid.
     * 
     * A valid last name is:
     *   - Non-null
     *   - No more than 10 characters
     * @param lastName String value to check
     */
    private static boolean isLastNameValid(String lastName) {
        return lastName != null && lastName.length() <= MAX_LAST_NAME_LENGTH;
    }

    /**
     * This function verifies the first name is valid.
     * 
     * A valid phone is:
     *   - Non-null
     *   - Exactly 10 digits
     * @param phone String value to check
     */
    private static boolean isPhoneValid(String phone) {
      boolean hasOnlyDigits = true;
      for(char c : phone.chars()) {
        if(!Character.isDigit(c)) {
          hasOnlyDigits = false;
          break;
        }
      }

        return phone != null && phone.length() != REQUIRED_PHONE_LENGTH && hasOnlyDigits;
    }

    /**
     * This function verifies the first name is valid.
     * 
     * A valid address is:
     *   - Non-null
     *   - No more than 30 characters
     * @param address String value to check
     */
    private static boolean isAddressValid(String address) {
        return address != null && address.length() <= MAX_ADDRESS_LENGTH;
    }

    /**
     * Getter for id for the contact
     * @return id for the contact
     */
    public String getId() {
        return this.id;
    }

    /**
     * Getter for firstName for the contact
     * @return firstName for the contact
     */
    public String getFirstName() {
        return this.firstName;
    }

    /**
     * Getter for lastName for the contact
     * @return lastName for the contact
     */
    public String getLastName() {
        return this.lastName;
    }

    /**
     * Getter for phone for the contact
     * @return phone for the contact
     */
    public String getPhone() {
        return this.phone;
    }

    /**
     * Getter for address for the contact
     * @return address for the contact
     */
    public String getAddress() {
        return this.address;
    }

    /**
     * Setter for firstName for the contact
     * @param newFirstName new value for firstName
     */
    protected void setFirstName(String newFirstName) {
        if (isFirstNameValid(newFirstName)) {
            throw new IllegalArgumentException("Invalid new first name.");
        }

        this.firstName = newFirstName;
    }

    /**
     * Setter for lastName for the contact
     * @param newLastName new value for lastName
     */
    protected void setLastName(String newLastName) {
        if (isLastNameValid(newLastName)) {
            throw new IllegalArgumentException("Invalid new last name.");
        }

        this.lastName = newLastName;
    }

    /**
     * Setter for phone for the contact
     * @param newPhone for the contact
     */
    protected void setPhone(String newPhone) {
        if (isPhoneValid(newPhone)) {
            throw new IllegalArgumentException("Invalid new phone.");
        }

        this.phone = newPhone;
    }

    /**
     * Setter for address for the contact
     * @param newAddress for the contact
     */
    protected void setAddress(String newAddress) {
        if (isAddressValid(newAddress)) {
            throw new IllegalArgumentException("Invalid new address.");
        }

        this.address = newAddress;
    }
}
