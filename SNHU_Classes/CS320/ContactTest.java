package contact_service;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.*;

public class ContactTest {
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

    @Nested
    @Tag("Creation")
    class WhenCreated {
        @Test
        @RepeatedTest(5)
        @DisplayName("Creates Contact when all values are random and valid")
        void createContactWithValidInput() {
            String testId = generateRandomString(Contact.MAX_ID_LENGTH);
            String testFirstName = generateRandomString(Contact.MAX_FIRST_NAME_LENGTH);
            String testLastname = generateRandomString(Contact.MAX_LAST_NAME_LENGTH);
            String testPhone = generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH);
            String testAddress = generateRandomString(Contact.MAX_ADDRESS_LENGTH);

            Contact testContact = new Contact(
                testId,
                testFirstName,
                testLastname,
                testPhone,
                testAddress,
            );

            assertAll(
                "contact",
                () - > assertEquals(testId, testContact.getId()),
                () - > assertEquals(testFirstName, testContact.getFirstName()),
                () - > assertEquals(testLastName, testContact.getLastName()),
                () - > assertEquals(testPhone, testContact.getPhone()),
                () - > assertEquals(testAddress, testContact.getAddress()));
        }

        @Test
        @DisplayName("Creates Contact when all non-null, no length minimum values are empty strings")
        void createContactWithNonnullEmptyStringInput() {
            String testId = "";
            String testFirstName = "";
            String testLastname = "";
            String testPhone = generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH);
            String testAddress = "";

            Contact testContact = new Contact(
                testId,
                testFirstName,
                testLastname,
                testPhone,
                testAddress,
            );

            assertAll(
                "contact",
                () - > assertEquals(testId, testContact.getId()),
                () - > assertEquals(testFirstName, testContact.getFirstName()),
                () - > assertEquals(testLastName, testContact.getLastName()),
                () - > assertEquals(testPhone, testContact.getPhone()),
                () - > assertEquals(testAddress, testContact.getAddress()));
        }

        @Test
        @DisplayName("Throws invalid id when id is null")
        void nullIDThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {

                new Contact(
                    null,
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid id.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid id when id is too long")
        void tooLongIDThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH + 1),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid id.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid first name when first name is null")
        void nullFirstNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    null,
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid first name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid first name when first name is too long")
        void tooLongFirstNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH + 1),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid first name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid last name when last name is null")
        void nullLastNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    null,
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid last name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid last name when last name is too long")
        void tooLongLastNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH + 1),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid last name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid phone when phone is null")
        void nullPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    null,
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid phone when phone is too short")
        void tooLongPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH - 1),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid phone when phone is too long")
        void tooShortPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH + 1),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH),
                );
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid address when address is null")
        void nullAddressThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    null,
                );
            });
            assertEquals("Invalid address.", exception.getMessage());
        }


        @Test
        @DisplayName("Throws invalid address when address is too long")
        void tooLongAddressThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                new Contact(
                    generateRandomString(Contact.MAX_ID_LENGTH),
                    generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                    generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                    generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                    generateRandomString(Contact.MAX_ADDRESS_LENGTH + 1),
                );
            });
            assertEquals("Invalid address.", exception.getMessage());
        }
    }

    @Nested
    @Tag("Update")
    class WhenUpdated {
        private Contact testContact;

        @BeforeEach
        void setup() {
            testContact = new Contact(
                generateRandomString(Contact.MAX_ID_LENGTH),
                generateRandomString(Contact.MAX_FIRST_NAME_LENGTH),
                generateRandomString(Contact.MAX_LAST_NAME_LENGTH),
                generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH),
                generateRandomString(Contact.MAX_ADDRESS_LENGTH),
            );
        }

        @Test
        @RepeatedTest(5)
        @DisplayName("Updates Contact when all values are random and valid")
        void updateContactWithValidInput() {
            String testId = generateRandomString(Contact.MAX_ID_LENGTH);
            String testFirstName = generateRandomString(Contact.MAX_FIRST_NAME_LENGTH);
            String testLastname = generateRandomString(Contact.MAX_LAST_NAME_LENGTH);
            String testPhone = generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH);
            String testAddress = generateRandomString(Contact.MAX_ADDRESS_LENGTH);

            testContact.setId(testId);
            testContact.setFirstName(testFirstName);
            testContact.setLastName(testLastName);
            testContact.setPhone(testPhone);
            testContact.setAddress(testAddress);

            assertAll(
                "contact",
                () - > assertEquals(testId, testContact.getId()),
                () - > assertEquals(testFirstName, testContact.getFirstName()),
                () - > assertEquals(testLastName, testContact.getLastName()),
                () - > assertEquals(testPhone, testContact.getPhone()),
                () - > assertEquals(testAddress, testContact.getAddress()));
        }

        @Test
        @DisplayName("Updates Contact when all non-null, no length minimum values are empty strings")
        void updateContactWithNonnullEmptyStringInput() {
            String testId = "";
            String testFirstName = "";
            String testLastname = "";
            String testAddress = "";

            assertAll(
                "contact",
                () - > assertEquals(testId, testContact.getId()),
                () - > assertEquals(testFirstName, testContact.getFirstName()),
                () - > assertEquals(testLastName, testContact.getLastName()),
                () - > assertEquals(testAddress, testContact.getAddress()));
        }

        @Test
        @DisplayName("Throws invalid first name when first name is null")
        void nullFirstNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setFirstName(null);
            });
            assertEquals("Invalid first name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid first name when first name is too long")
        void tooLongFirstNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setFirstName(generateRandomString(Contact.MAX_FIRST_NAME_LENGTH + 1));
            });
            assertEquals("Invalid first name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid last name when last name is null")
        void nullLastNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setLastName(null);
            });
            assertEquals("Invalid last name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid last name when last name is too long")
        void tooLongLastNameThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setLastName(generateRandomString(Contact.MAX_LAST_NAME_LENGTH + 1));
            });
            assertEquals("Invalid last name.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid phone when phone is null")
        void nullPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setPhone(null);
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @Repeated(5)
        @DisplayName("Throws invalid phone when phone contains non-digit characters")
        void nonDigitPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                String newPhone = generateRandomString(Contact.REQUIRED_PHONE_LENGTH);
                // Verify the whole new phone isn't digits only
                while(newPhone.matches("[0-9]+")) {
                  newPhone = generateRandomString(Contact.REQUIRED_PHONE_LENGTH);
                }
                testContact.setPhone();
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid phone when phone is too short")
        void tooLongPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setPhone(generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH - 1));
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid phone when phone is too long")
        void tooShortPhoneThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setPhone(generateRandomDigitString(Contact.REQUIRED_PHONE_LENGTH + 1));
            });
            assertEquals("Invalid phone.", exception.getMessage());
        }

        @Test
        @DisplayName("Throws invalid address when address is null")
        void nullAddressThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setAddress(null);
            });
            assertEquals("Invalid address.", exception.getMessage());
        }


        @Test
        @DisplayName("Throws invalid address when address is too long")
        void tooLongAddressThrows() {
            Throwable exception = assertThrows(IllegalArgumentException.class, () - > {
                testContact.setAddress(generateRandomString(Contact.MAX_ADDRESS_LENGTH + 1));
            });
            assertEquals("Invalid address.", exception.getMessage());
        }
    }
}
