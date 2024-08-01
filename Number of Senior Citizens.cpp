class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0; // Initialize the counter for seniors
        for(int i = 0; i < details.size(); i++) { // Loop through each string in the details vector
            // Extract the substring that represents the age and convert it to an integer
            if (stoi(details[i].substr(11, 2)) > 60) { // Compare the extracted age to 60
                count++; // Increment the counter if the age is greater than 60
            }
        }
        return count; // Return the final count of seniors
    }
};