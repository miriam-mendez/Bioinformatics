# Computational methods in Bioinformatics. Assignment 2. Exercise 2. Pablo Vadillo Berganza

# To compile this py program, first we create the executable:

# pyinstaller --onefile essential.py

# To run the program, type:

# ./dist/essential

# import pandas lib as pd
import pandas as pd

input_data = pd.read_csv("ccm.csv")

endpoints = list(input_data[81:93]["To"].values)


def bfs(data, initial):

    p = []
    queue = [initial]
    while len(queue) > 0:
        node = queue.pop(0)
        queue.extend(data.loc[data["From"] == node]["To"].values)
        data2 = data.loc[(data["From"] != node) & (data["To"] != node)]
        data = data2
        if node not in p:
            p.append(node)

    return p


def essential(data, name, initial, goal):

    enzymes_0 = list(data["Enzyme"].values)
    enzymes = []
    for i in enzymes_0:
        if i not in enzymes:
            enzymes.append(i)

    essen = []

    for j in enzymes:
        data2 = data.loc[data["Enzyme"] != j]
        p = bfs(data2, initial)
        for k in goal:
            if k not in p and j not in essen:
                essen.append(j)

    print("The essential enzymes in {} are {}.".format(name, essen))


if __name__ == '__main__':
    essential(input_data, "central carbon metabolism", "Glucose [c]", endpoints)
