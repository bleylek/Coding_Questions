"""
DataFrame: employees
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| employee_id | int    |
| name        | object |
| department  | object |
| salary      | int    |
+-------------+--------+
Write a solution to display the first 3 rows of this DataFrame.

 

Example 1:

Input:
DataFrame employees
+-------------+-----------+-----------------------+--------+
| employee_id | name      | department            | salary |
+-------------+-----------+-----------------------+--------+
| 3           | Bob       | Operations            | 48675  |
| 90          | Alice     | Sales                 | 11096  |
| 9           | Tatiana   | Engineering           | 33805  |
| 60          | Annabelle | InformationTechnology | 37678  |
| 49          | Jonathan  | HumanResources        | 23793  |
| 43          | Khaled    | Administration        | 40454  |
+-------------+-----------+-----------------------+--------+
Output:
+-------------+---------+-------------+--------+
| employee_id | name    | department  | salary |
+-------------+---------+-------------+--------+
| 3           | Bob     | Operations  | 48675  |
| 90          | Alice   | Sales       | 11096  |
| 9           | Tatiana | Engineering | 33805  |
+-------------+---------+-------------+--------+
Explanation: 
Only the first 3 rows are displayed.
"""


import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3) #it returns the first 3 rows of the employees DataFrame by calling the head(3) method on it.



# Assuming 'employees' DataFrame is already defined as in the previous examples:
# Sample data for the demonstration
data = {
    'employee_id': [101, 102, 103, 104, 105],
    'name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'department': ['HR', 'IT', 'Finance', 'Marketing', 'IT'],
    'salary': [50000, 60000, 55000, 45000, 70000]
}

# Creating the DataFrame
employees = pd.DataFrame(data)

# Using the function
first_three_rows = selectFirstRows(employees)

# Display the result
print(first_three_rows)
