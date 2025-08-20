# CS360 Module 8 Journal

The purpose of this journal is to provide student reflection on mobile application development through Android Studio.

# Briefly summarize the requirements and goals of the app you developed. What user needs was this app designed to address?

The application developed through this course had the goal of providing users with a way to login and view inventory stored on the device hosting the application. It was created to address the needs of users who need to manipulate and monitor inventory.

# What screens and features were necessary to support user needs and produce a user-centered UI for the app? How did your UI designs keep users in mind? Why were your designs successful?

The application screens needed to include a login screen for the user to verify they had access to the application, list screen to display the information from the on-device database, item details screen to allow users to make changes to the items, and a dialog to allow users to provide permissions for the application.

My designs kept the users in mind by focusing on simplistic and minimalist approaches to keep the movement through the application intuitive and clear. These designs were successful with the combination of their simplicity and leveraging the basic principles outlined by the Material 3 guidelines.

# How did you approach the process of coding your app? What techniques or strategies did you use? How could those techniques or strategies be applied in the future?

For this application I initially approached the coding aspect by writing out the XML files for the layouts and verifying they appeared as I expected in the Android Studio layout editor, similar to writing out the HTML to starting a web page. I utilized an incremental approach to get the visible part of the application in a state that it needed to be hooked up, as this seemed more what Android studio was intended to do for development. I then added the asset files for the project. Finally I wrote the models and controllers to handle the programmatic changes in the application. In the future I will look to leverage creating the source code functionality first with unit tests, and then hooking up the UI for functionality.

# How did you test to ensure your code was functional? Why is this process important, and what did it reveal?

Due to time constraints and unfamiliarity with Android Studio, I opted to leverage manual testing for verifying this application was functional; however, in the future I would aim to introduce unit and integration tests instead as an automated approach that better supports future development. The process of testing is extremely important to make sure the application first of all is functional without crashing. It's also important to provide a way for other developers on a team to see how the code can be proved right, even if the elements associated with the code may not be fully implemented.

# Consider the full app design and development process from initial planning to finalization. Where did you have to innovate to overcome a challenge?

I had to innovate with my approach to working in an IDE that was very unfamiliar to me. Typically, all of my development is done in Vim based environments or VS Code, both of which leverage keystrokes and commands. A big difference was the high reliance of developing in Android Studio for mouse utilization. Aside from this tool, I did begin exploring Figma as a way to plan out and easily arrange app elements to plan out an application that would look nice and make sense from the perspective of a user.

# In what specific component of your mobile app were you particularly successful in demonstrating your knowledge, skills, and experience?

I feel like the database setup and design, while small, was something that demonstrated my skills. While this needs to be refined for increased security in a real-world application and leveraging foreign keys to tie items to users, it was something I felt was designed well decoupled from the UI elements themselves.
