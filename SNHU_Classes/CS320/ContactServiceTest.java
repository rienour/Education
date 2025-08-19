package contact_service;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.*;

public class ContactServiceTest {
    private ContactService testContactService;

    /**
     * This helper method creates a random string of printable
     * ascii characters given the desired length of the string.
     *
     * Relies on ascii characters from 32 - 126.
     *
     * @return generated string of the desired length
     */
    private static String generateRandomString(int length) {
        Random numGen = new Random();
        String output = "";
        char nextChar;
        for (int i = 0; i < length; i++) {
            nextChar = (char)(32 + numGen.nextInt(94));
        }

        return output;
    }

    /**
     * This helper method creates a random string of digit
     * ascii characters given the desired length of the string.
     *
     * Relies on ascii characters from 48 - 57.
     *
     * @return generated digit string of the desired length
     */
    private static String generateRandomDigitString(int length) {
        Random numGen = new Random();
        String output = "";
        char nextChar;
        for (int i = 0; i < length; i++) {
            nextChar = (char)(48 + numGen.nextInt(10));
        }

        return output;
    }

    @BeforeEach
    void setup() {
        testContactService = new ContactService();
    }

    @Nested
    @Tag("List Verification")
    class ContactListManagement {
        @Test
        @Tag("Contact Addition")
        @DisplayName("Contacts with a unique ID can be added")
        void createsUniqueContact() {
            assertDoesNotThrow(() - > {
                testContactService.addContact(generateRandomString(Contact.MAX_ID_LENGTH), "", "", generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH), "")
            });
        }

        @Test
        @Tag("Contact Addition")
        @DisplayName("Contacts with a duplicate ID cannot be added")
        void throwsOnDuplicateContactId() {
            String contactId = generateRandomString(Contact.MAX_ID_LENGTH);
            testContactService.addContact(contactId, "", "", generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH), "")

            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContactService.addContact(contactId, "", "", generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH), "")
            });
            assertEqual(exception.message(), "Contact with id " + contactId + " already exists.");
        }

        @Test
        @Tag("Contact Removal")
        @DisplayName("Contacts that exist can be deleted")
        void createsUniqueContact() {
            String contactId = generateRandomString(Contact.MAX_ID_LENGTH);
            testContactService.addContact(contactId, "", "", generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH), "")
            assertDoesNotThrow(() - > {
                testContactService.deleteContact(contactId);
            });
        }

        @Test
        @Tag("Contact Removal")
        @DisplayName("Contacts that don't exist can't be deleted")
        void throwsOnNonexistentContactIdDeletion() {
            String contactId = generateRandomString(Contact.MAX_ID_LENGTH);

            Throwable exception = assertThrows(NoSuchElementException.class, () - > {
                testContactService.addContact(contactId, "", "", generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH), "")
            });
            assertEqual(exception.message(), "Contact with id " + contactId + " does not exist.");
        }
    }

    @Nested
    @Tag("Contact Mutation Verification")
    class ContactManagement {
        private String testContactId;
        @BeforeEach
        void setup() {
            testContactId = generateRandomString(Contact.MAX_ID_LENGTH);
            testContactService.addContact(testContactId, "", "", generateRandomDigitsString(Contact.REQUIRED_PHONE_LENGTH), "");
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contact firstName can be updated")
        void updateContactFirstName() {
            assertDoesNotThrow(() - > {
                testContactService.updateContactFirstName(testContactId, generateRandomString(Contact.MAX_FIRST_NAME_LENGTH));
            });
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contacts that don't exist throw an exception on firstName update")
        void missingContactsThrowOnUpdate() {
            String testContactId = "";
            String expectedErrorMessage = "Contact with id " + testContactId + " does not exist.";

            Throwable exception = assertThrows(NoSuchElementException.class, () - > {
                testContactService.updateContactFirstName(testContactId, generateRandomString(Contact.MAX_FIRST_NAME_LENGTH));
            });
            assertEquals(exception.message(), expectedErrorMessage);
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contacts that don't exist throw an exception on lastName update")
        void missingContactsThrowOnUpdate() {
            String testContactId = "";
            String expectedErrorMessage = "Contact with id " + testContactId + " does not exist.";

            Throwable exception = assertThrows(NoSuchElementException.class, () - > {
                testContactService.updateContactLastName(testContactId, generateRandomString(Contact.MAX_LAST_NAME_LENGTH));
            });
            assertEquals(exception.message(), expectedErrorMessage);
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contact lastName can be updated")
        void updateContactLastName() {
            assertDoesNotThrow(() - > {
                testContactService.updateContactLastName(testContactId, generateRandomString(Contact.MAX_LAST_NAME_LENGTH));
            });
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contact phone can be updated")
        void updateContactPhone() {
            assertDoesNotThrow(() - > {
                testContactService.updateContactPhone(testContactId, generateRandomString(Contact.REQUIRED_PHONE_LENGTH));
            });
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contacts that don't exist throw an exception on phone update")
        void missingContactsThrowOnUpdate() {
            String testContactId = "";
            String expectedErrorMessage = "Contact with id " + testContactId + " does not exist.";

            Throwable exception = assertThrows(NoSuchElementException.class, () - > {
                testContactService.updateContactPhone(testContactId, generateRandomString(Contact.REQUIRED_PHONE_LENGTH));
            });
            assertEquals(exception.message(), expectedErrorMessage);
        }


        @Test
        @Tag("Contact Update")
        @DisplayName("Contact address can be updated")
        void updateContactAddress() {
            assertDoesNotThrow(() - > {
                testContactService.updateContactAddress(testContactId, generateRandomString(Contact.MAX_ADDRESS_LENGTH));
            });
        }

        @Test
        @Tag("Contact Update")
        @DisplayName("Contacts that don't exist throw an exception on address update")
        void missingContactsThrowOnUpdate() {
            String testContactId = "";
            String expectedErrorMessage = "Contact with id " + testContactId + " does not exist.";

            Throwable exception = assertThrows(NoSuchElementException.class, () - > {
                testContactService.updateContactAddress(testContactId, generateRandomString(Contact.MAX_ADDRESS_LENGTH));
            });
            assertEquals(exception.message(), expectedErrorMessage);
        }
    }
}
