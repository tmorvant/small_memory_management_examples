Project explanation per asminer@iastate.edu:

    There are exactly 9 program variables, numbered 1 through 9. These are initialized to the NULL pointer.
    The first line of the input file specifies the number of nodes N. Nodes are numbered 1 through N.
    Each node has a single outgoing pointer, initially NULL.
    The remainder of the input file are assignment statements, one per line, to be processed in order. An assignment statement may overwrite a previous assignment.
    An assignment statement of the form
    L nodesrc->nodedest
    sets the outgoing pointer of nodesrc (a node index from 1 through N) to nodedest (either 0, signifying a NULL pointer, or a node index from 1 through N).
    An assignment statement of the form
    V varnum->nodedest
    sets the variable varnum (an integer from 1 to 9) to nodedest (either 0, signifying a NULL pointer, or a node index from 1 through N).
    If any integer value is outside of the correct range, print an error message to stderr and exit.
    Once all the input has been processed, your program should display, for each node (in order) with at least one incoming pointer, the reference count for the node.

An input.txt is an example of a correctly formatted input file. Input file name passed as argument to run file.