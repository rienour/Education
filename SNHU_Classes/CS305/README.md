# CS305: Software Security - Module 8 Journal

The purpose of this journal is to provide students with reflection on the material learned in the course relating to software security practices.

# Questions

1. Briefly summarize your client, Artemis Financial, and its software requirements. Who was the client? What issue did the company want you to address?

The client, Artemis Financial, would like to modernize its web-based software application and place a focus on securing the RESTful web API. The client has a need to enforce secure communications to abide by various national regulations and maintain a positive image for their own customers. While there is no explicit statement that Artemis performs global transactions, financial transactions are commonly conducted globally. As such, it can be assumed that the client handles both localized and global transactions. There are various levels of governmental restrictions dependent on the domain, such as FTC Safeguards Requirements within the United States, CCPA in California in the United States, and GDPR in the European Union. The client aimed to address modernizing and securing their RESTful Web API.

1. What did you do well when you found your client’s software security vulnerabilities? Why is it important to code securely? What value does software security add to a company’s overall well-being?

One thing that I performed well was doing enough research to try to understand the client requirements in their business domain and then utilize this knowledge to understand what it meant for their requirements. When finding the security vulnerabilities, it was important to verify that there was a plan to mitigate or resolve the vulnerabilities to preserve the client’s trustworthiness to their own clients.

It is important to code securely to prevent harming the users of an application and to adhere to the principles outlined in the [IEEE](https://www.computer.org/education/code-of-ethics) Code of Ethics. Protecting the user and adhering to ethical principles are the two main reasons, however it can also lead to more maintainable, efficient, and higher quality code. These secondary benefits are good for the longevity of the company to prevent unnecessary costs related to insecure software development practices.

1. Which part of the vulnerability assessment was challenging or helpful to you?

The most challenging part of a vulnerability assessment, performed through a Maven dependency check in the context of this course, was addressing the suppression of false positives. It is ambiguous to understand when to mark something as a false positive, since it's possible that changes could be made to the application that results in a false positive becoming a true positive. It was helpful to gain exposure to this tool to start performing more research to understand the real-world application of the tool and gain exposure to a component that could be part of the Secure Software Development Lifecycle.

1. How did you increase layers of security? In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use?

I increased the layer of security for their application by introducing a REST endpoint that handled providing an SHA256 checksum for a string in the application. With these changes, I also update the application to utilize an SSL connection over HTTPS to protect the data between client and server in transit.

In the future, I would utilize the Vulnerability assessment flow diagram at a high level to break up assessing the vulnerabilities by conducting an initial review of the code architecture, conducting a review on the components that interact within the code base (Input Validation, error handling, communications, ect.), audit the individual components of the design pattern (client, server, model, view, etc.), perform static testing through dependency checkers, and finally investigate options for dynamic testing. Once this information had been put together, I'd create a mitigation plan, and then once the plan was put into place the cycle would iterate again to verify the new system is secure starting from the beginning of the cycle.

1. How did you make certain the code and software application were functional and secure? After refactoring the code, how did you check to see whether you introduced new vulnerabilities?

I utilized the Maven Dependency check tool to verify that the starting state and ending state of the application did not include any additional vulnerabilities, while addressing the client requirements for their project. I reviewed the implementation to verify that the changes adhered to the secure principles through the steps outlined above.


1. What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks?

The Maven repository, NVD database, and NIST website are all resources that can provide insight to the libraries utilized. These resources will provide a starting point for researching libraries for prospective us in a project, prior to committing to them. These tools can offer a history of the project to determine if it was a habitual offender in the security field or if the vulnerabilities were unique and/or intermittent.

The Maven Dependency Check Tool was one of the most important tools utilized through the course, which provides a comprehensive report for analyzing the dependencies. This tool specifically would be something I'd consider utilizing as a step in a DevSecOps pipeline and code review process.

There were a lot of coding practices covered through the course, but specifically keeping an eye on the [OWASP Top Ten](https://owasp.org/www-project-top-ten/) would be an ongoing method to make sure common vulnerabilities are caught earlier and proper secure coding guidelines are implemented.


1. Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?

From this specific assignment I would show the steps I took to analyze the codebase and how vulnerabilities were identified. I would show case the migration from insecure coding practices to secure coding practices, such as the utilization of checksums and SSL communication.

