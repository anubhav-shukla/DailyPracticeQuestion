#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
// Utility function to print a unordered_set
void printSet(char c, unordered_set<char> const &v)
{
    cout << c << " —> [";
    int n = v.size();
    for (auto i: v) {
        cout << i;
        if (--n) {
            cout << ", ";
        }
    }
    cout << "]\n";
}
 
// Recursive DP function to find all employees who directly or indirectly
// report to a given manager and store the result in `result`
unordered_set<char> findAllReportingEmployees(char manager,
                                    auto &managerToEmployeeMappings,
                                    auto &result)
{
    // if the subproblem is already seen before
    if (result.find(manager) != result.end())
    {
        // return the already computed mapping
        return result[manager];
    }
 
    // find all employees reporting directly to the current manager
    unordered_set<char> managerEmployees = managerToEmployeeMappings[manager];
 
    // find all employees reporting indirectly to the current manager
    for (char reportee: managerToEmployeeMappings[manager])
    {
        // find all employees reporting to the current employee
        unordered_set<char> employees = findAllReportingEmployees(reportee,
                                            managerToEmployeeMappings, result);
 
        // move those employees to the current manager
        for (char c: employees) {
            managerEmployees.insert(c);
        }
    }
 
    // save the result to avoid recomputation and return it
    result[manager] = managerEmployees;
    return managerEmployees;
}
 
// Find all employees who directly or indirectly reports to a manager
unordered_map<char, unordered_set<char>> findEmployees(auto &employeeToManagerMappings)
{
    // store manager to employee mappings in a new map.
    // `unordered_set<char>` is used since a manager can have several employees mapped
    unordered_map<char, unordered_set<char>> managerToEmployeeMappings;
 
    // fill the above map with the manager to employee mappings
    for (auto it: employeeToManagerMappings)
    {
        char employee = it.first;
        char manager = it.second;
 
        // don't map an employee with itself
        if (employee != manager) {
            managerToEmployeeMappings[manager].insert(employee);
        }
    }
 
    // construct an ordered map to store the result
    unordered_map<char, unordered_set<char>> result;
 
    // find all reporting employees (direct and indirect) for every manager
    // and store the result in a map
    for (auto p: employeeToManagerMappings) {
        findAllReportingEmployees(p.first, managerToEmployeeMappings, result);
    }
 
    return result;
}
 
int main()
{
    // construct a mapping from employee to manager
    unordered_map<char, char> employeeToManagerMappings = {
        {'A', 'A'}, {'B', 'A'}, {'C', 'B'}, {'D', 'B'}, {'E', 'D'}, {'F', 'E'}
    };
 
    auto result = findEmployees(employeeToManagerMappings);
 
    // print contents of the resulting map
    for (auto p: result) {
        printSet(p.first, p.second);
    }
 
    return 0;
}
