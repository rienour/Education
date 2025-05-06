# CS210 Module 8 Journal

The purpose of this journal is to provide an opportunity to review and reflect on one of the course projects.

## Summary of Chosen Project

The purpose of this program is to demonstrate student competency in designing class and functional programs that comply with industry regulations. This will be demonstrated through an example grocery tracker utility.

The requirements for the project outline that the program needs to be capable of reading file input, writing a backup automatically to file output, prompting the user with a menu entry, and processing the data in visual formats through the selected menu entry.

## Project Strength

This project felt very well organized to maintain a clear separation of concerns. Notably the separation of the general utility functions, like `printCharNTimes` and the `GrocerTracker` class methods, like `PrintItemHistogram`. The separation of the menu into dedicated functions also felt like a good call in the event the program was intended to be expanded or adapted, but the menu functionality may only want to present certain options during the development process of new features.

## Project Improvements

One consideration I could've made was the arithmetic utilized withing the `GrocerTracker::PrintItemHistorgram` method. Despite being highly unlikely, it's possible that the name of an item could be the maximum allowed value for an unsigned int, which when incremented by 1 would result in a 0 value, which would print incorrectly based on the intended printing. While this specific instance this may not have presented as a security concern or stability concern, this is a consideration that should be carried over into other areas of general C++ development to avoid potential bugs.

## Challenges

The only piece of code in the project that wasn't something I could write without documentation was the utilization of the STL map. I've utilized the same construct in JavaScript/TypeScript through work but hadn't worked with the implementation in C++ before. Since this was a syntax related challenge, I pulled up cppreference.com and navigated to the page about the map. Once I had the documentation up, there weren't any challenging components left code wise. As a result of this syntax challenge, there weren’t any new resources or tools added to my network yet since I've heavily utilized cppreference in the past.

## General Application of Skills

In general, the encapsulation and separation of concerns for the elements of the program will be very meaningful in general development. Being able to create these abstractions and manage the messages passed between objects are very important, especially as an application will grow or eventually enter a maintenance phase. Incremental development was also a skill that will be very impactful, especially for courses where the project size and complexity will continue to grow. With preparation for those changes, further refinement of my C++ unit/integration testing skills will be something to take from this project as well.

## How was this program made maintainable, readable, and adaptable?

This program was designed to be matainable through the modularity of the functions and class. The class encapsulates specific logic in the methods to limit the responsibilities of an individual method to a minimum, while achieving a singular goal. The utilization of single responsibility functions makes it easy to add testing to prevent regressions as the project was to grow with clear, well defined operational units. Additionally, the logging included in some of the functions prevents "eating" errors or silently erroring without the user knowledge.

The readability of this program is partially coupled with the encapsulation techniques utilized, but most of it comes from the utilization of the doxygen styles comments. While there was no documentation generated based on the comments in this program, the familiarity to other developers will make it easier to read the comments. The utilization of appropriate variable and function names also provides context, while allowing the code to be self-documenting.

The adaptability of this program is again tied to the encapsulation techniques utilized to keep clear separation of responsibilities. For example, `getShort` is not tightly coupled to the implementation for this program, despite needing to be in a single file to meet project requirements. 

