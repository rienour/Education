# CS300: DSA Analysis and Design

The purpose of this module is to reflect on the student understanding of data structures and algorithms as they relate to solving real world problems.

# Questions

1. What was the problem you were solving in the projects for this course?

The projects for this course focused on looking at a problem domain and understanding how the choice of data structures can impact the performance of an application. The assignments focused on implementing different data structures and looking at how the clock ticks consumed by the processor differed based on the situation.

2. How did you approach the problem? Consider why data structures are important to understand.

For this specific assignment I approached the problem by first understanding the requirements of the system, which was to offer course loading, printing, and searching capabilities. Once the requirements were understood I connected the requirements of the project to the business domain to get an understanding of how the application will be utilized by users. This analysis provided insight to guide the decision of a data structure to utilize that would balance the complexity, runtime, and maintainability of the application as it may grow. Once the requirements and business domain were understood, I reviewed the algorithms and data structures that would be utilized to determine what data structure provided the best combination of attributes, considering the memory footprint and searching time as the most important aspects for the application.

It's important to understand the use of and implementations of data structures to create programs that are performant, robust, and maintainable by other developers. Code will be read by a human more times than it will ever be written. Utilizing common data structures can quickly provide guidance to a developer to quickly dive into the program and expand upon it, even if the original developer is no longer available to do so.

3. How did you overcome any roadblocks you encountered while going through the activities or project?

If I encountered roadblocks, my first step was always to review what the roadblock was to determine if it was a logical error or some other kind of error. Logical errors lead to utilization of the debugger to step through the program and determine what steps were not performing the intended logic. Other types of errors, such as compile time errors, lead me to the [C++ Reference documentation](https://cppreference.com/) to review the functionality of the language I was using to determine if there were syntactical errors not caught by the clangd LSP I utilized during development. If debugging and documentation did not provide answers, then I resulted to research to determine if other developers had experienced similar problems to analyze their solutions and determine if the found solution was appropriate and the solution as understood prior to utilization.

4. How has your work on this project expanded your approach to designing software and developing programs?

The work on this project has expanded my approach to developing software by allowing me to further understand why consistent public APIs for a data structure are important for data encapsulation to ensure the application is performant, maintainable, and expandable without requiring future developer's to perform an overhaul of the changes made previously. Additionally, the utilization of documentation generation libraries and writing comments that could generate the documentation has further solidified the need for writing appropriate and good documentation that balances the amount of information presented and quality of the presented information

5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

The work on this project has made me further understand the importance of data encapsulation to prevent inappropriate types of cohesion between classes. It's reiterated the idea that small responsibility functions and classes are the most appropriate approach to maintain developer understanding of the codebase.
