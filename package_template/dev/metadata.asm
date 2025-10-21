section .rodata:
    global versionMAJOR
    global versionINTERMEDIATE
    global versionMINO
    global author
    global description

    ; Version 0.1.0
    dd versionMAJOR = 0
    dd versionINTERMEDIATE = 1
    dd versionMINOR = 0

    db author = 'John Doe', 0
    db description = 'Description goes here', 0