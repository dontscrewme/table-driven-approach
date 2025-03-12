# table-driven-approach

Before refactoring, the code relied on multiple if-else chains to check each command and execute the corresponding logic. This approach was repetitive, error-prone, and difficult to maintain as new commands were added.

To simplify this, I introduced a lookup table (cmd_table[]) that mapped each command to its respective data and actions.

If the command requires additional actions (e.g., checking access rights, moving data to ROM, or showing results), those are also defined within the structure and executed accordingly.

This approach centralizes the command logic in one place, reducing redundancy and making the code easier to maintain and extend. Adding or modifying a command now only requires an update to the table — no need to touch the main logic.
