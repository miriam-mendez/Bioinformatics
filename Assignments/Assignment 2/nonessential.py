# Computational methods in Bioinformatics. Assignment 2. Exercise 1. Pablo Vadillo Berganza

# To compile this py program, first we create the executable:

# pyinstaller --onefile nonessential.py

# To run the program, type:

# ./dist/nonessential

# import pandas lib as pd
import pandas as pd

input_data = pd.read_csv("glycolysis.csv")


def bfs(data, initial):

    p = []
    queue = [initial]
    while len(queue) > 0:
        node = queue.pop(0)
        queue.extend(data.loc[data["Input"] == node]["Output"].values)
        data2 = data.loc[(data["Input"] != node) & (data["Output"] != node)]
        data = data2
        if node not in p:
            p.append(node)

    return p


def non_essential(data, name, initial, goal):

    enzymes_0 = list(data["Enzyme"].values)
    enzymes = []
    for i in enzymes_0:
        if i not in enzymes:
            enzymes.append(i)

    nonessential = []
    for j in enzymes:
        data2 = data.loc[data["Enzyme"] != j]
        p = bfs(data2, initial)
        if goal in p:
            nonessential.append(j)

    print("The non-essential enzymes in {} are {}.".format(name, nonessential))


if __name__ == '__main__':
    non_essential(input_data, "glycolysis", "Glucose", "Pyruvate")
