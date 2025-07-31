/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    
    An input string is valid if:
        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.
    
    Example 1:
    - Input: s = "()"
    - Output: true
    Example 2:
    - Input: s = "()[]{}"
    - Output: true    
    Example 3:
    - Input: s = "(]"
    - Output: false
    Example 4:
    - Input: s = "([])"
    - Output: true
    Example 5:
    - Input: s = "([)]"
    - Output: false
*/
const isValid = (str: string): boolean => {
  // Define object to track valid items combinations
  const validPairings = {
    '(': ')',
    '{': '}',
    '[': ']',
  } as const;

  // Stack to track the characters as they are seen
  const charStack: string[] = [];
  // Iterate through the items
  for(const item of str.split('')) {
    // If it's an opening bracket
    if(validPairings[item]) {
      charStack.push(item);
    } else {
      // It's a closing without an opening
      if (charStack.length === 0) {
        return false;
      }
      // It's a closing and the opening needs to be checked
      else {
        const stackTop = charStack[charStack.length - 1];
        if (validPairings[stackTop] === item) {
          charStack.pop()
        } else {
         return false;
        }
      }
    }
  }

  return charStack.length === 0;
};

console.log(
  [
    isValid("()"), // true
    isValid("()[]{}"), // true
    isValid("(]"), // false
    isValid("([])"), // true
    isValid("([)]"), // false
  ].map(String)
)
