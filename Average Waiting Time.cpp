class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // Assume that when the first customer enter the chef has just finished preparing a order
        // So he can immediately start preparing the order of the first customer
        
        // It is the time when the chef finishes preparing the order
        int endPreparing = customers[0][0];

        long long sum = 0;
        for(auto it: customers)
        {
            int startPreparing = max(endPreparing, it[0]); // The time when chef starts preparing the order for the customer
            // It is max of endPreparing and arrival time because:
            // Consider a customer that arrives at time = 2
            // Suppose the chef has completed preparing an order at time = 3 --> endPreparing
            // Then he will start preparing the order at time = 3 or max(endPreparing, arrival time)
            // Suppose another customer arrives at time = 4 and the chef has completed preparing the order at time = 3
            // They will not start preparing the order untill the customer's arrives i.e startPreparing = 4

            // The customer will start waiting when he arrives
            int startWaiting = it[0];

            // The time when the chef will complete the customer's order
            endPreparing = startPreparing + it[1];

            // Waiting time for that customer
            sum += endPreparing - startWaiting;
        }

        double avg = sum / (double)customers.size();

        return avg;
    }
};