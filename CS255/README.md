# CS255 Module 8 Journal

The purpose of this journal is to reflect on the work done in the design based on client requirements and system diagrams.

## DriverPass Project Summary

The client was the business Owner Liam and his IT Manager Ian. DriverPass sought to provide a way to provide drivers with better means of refining their driving skills to prepare for their driving test at the Department of Motor Vehicles (DMV) as too many students are failing their driving tests. It aimed to solve the problems of too many students failing the driving exam on their first attempt. The system should provide users with the tools to better prepare for their driving tests including written tests, scheduled driving sessions, and feedback. This system aimed to fill a void on the marker for providing student drivers resources to prepare for their test.

## Project Work Strength

Determining the concrete representations of the client set requirements was something that I felt went well. Determining the appropriate technologies for the anticipated scope of the project, by locking the client into an application that could not grow with their user base.

## Project Work Improvement

If I could revisit one part of this project to further revise, then I would likely pick the class diagram. While it does encompass a lot of the system functionality, it could use more details about the associations between objects or abstract connections. For example, DMV was just set in a class, however this likely would’ve been better represented through a class that indicated it was a DMV connector that reaches out to the DMV on behalf of the system rather than direct integration with the DMV itself. An Entity Relationship Diagram likely would've emphasized this diagram nicely and helped during the refinement, which could've been another piece of documentation that overall improved the design.

## Interpretation and Implementations of User needs into System Design

I interpreted the user's needs by understanding they had a clear goal in mind they wanted to accomplish, but did not understand the tools to accomplish that goal. The client provided details on what they wanted "something" to be able to do, which in their mind the "something" was their application they would eventually receive. Getting the abstract details from the user provided a way to gradually make changes to a design and prompt more questions to gradually work toward a concrete enough representation of their product that project work could be planned and started.

It's crucial to consider the needs of the user within the context of a system as the system is designed for the user to utilize. If the user's needs aren't considered when designing, then they won't be considered when implementing or maintaining the system either. The lack of this consideration sets a project up for failure before the project begins.

## Software Design Approach

In general, I approach software design by first getting the broad idea presented by a user or stakeholder at the basic level. Once the core of the user goal has been clearly established, I will ask more questions to gather further requirements and revise my understanding of the requirements presented so far. As the process continued, I would make sure to provide recaps to the User(s)/Stakeholder(s) to verify a mutual understanding about the vision of the project. Interviews are one of my most valuable tools that I've utilized professionally, both in a singular and group setting. With the amount of success I've had with this technique, it would be something I continued to utilize in the system. Through the CS255 course I've found some similarities in the diagrams and methodologies presented in the IT315 course, so I will be looking to leverage those diagrams more as I continue my work in software development.

