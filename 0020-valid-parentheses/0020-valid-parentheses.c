bool isValid(char* s) {
    int n = strlen(s);
    
    // Quick check: odd-length strings can't have balanced brackets
    if (n % 2 != 0) return false;
    
    // Use character array as stack
    char stack[n];
    int top = 0;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        
        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            stack[top++] = c;
        } 
        // Process closing brackets
        else {
            // Check if stack is empty
            if (top == 0) return false;
            
            // Get matching opening bracket
            char last = stack[--top];
            
            // Verify matching pair
            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                return false;
            }
        }
    }
    
    // Valid only if stack is empty
    return top == 0;
}