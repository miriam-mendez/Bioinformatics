# Computational methods in Bioinformatics. Assignment 2. Exercise 3. Pablo Vadillo Berganza

# To compile this py program, first we create the executable:

# pyinstaller --onefile cancercells.py

# To run the program, type:

# ./dist/cancercells

# import pandas lib as pd
import pandas as pd

input_data = pd.read_csv("ccm.csv")

rnacounts = pd.read_csv("RNAcounts.csv")

healthy_data_0 = pd.merge(input_data, rnacounts[["Enzyme", "Healthy RNA count"]], on="Enzyme", how="left")
healthy_data = healthy_data_0.loc[healthy_data_0["Healthy RNA count"] != 0]

cancer_data_0 = pd.merge(input_data, rnacounts[["Enzyme", "Cancer RNA count"]], on="Enzyme", how="left")
cancer_data = cancer_data_0.loc[cancer_data_0["Cancer RNA count"] != 0]
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


def cancer(healthydata, cancerdata, initial, goal):

    healthy_enzymes_0 = list(healthydata["Enzyme"].values)
    healthy_enzymes = []
    for i in healthy_enzymes_0:
        if i not in healthy_enzymes:
            healthy_enzymes.append(i)

    cancer_enzymes_0 = list(cancerdata["Enzyme"].values)
    cancer_enzymes = []
    for i in cancer_enzymes_0:
        if i not in cancer_enzymes:
            cancer_enzymes.append(i)

    cancer_essential = []

    for j in cancer_enzymes:
        cancerdata2 = cancerdata.loc[cancerdata["Enzyme"] != j]
        p = bfs(cancerdata2, initial)
        for k in goal:
            if k not in p and j not in cancer_essential:
                cancer_essential.append(j)

    healthy_nonessential = []

    for j in healthy_enzymes:
        healthydata2 = healthydata.loc[healthydata["Enzyme"] != j]
        p = bfs(healthydata2, initial)
        if set(goal).issubset(p) and j not in healthy_nonessential:
            healthy_nonessential.append(j)

    solution = []
    for i in cancer_essential:
        if i in healthy_nonessential:
            solution.append(i)
        if i not in healthy_enzymes:
            solution.append(i)

    print("The enzymes suitable to target in order to kill cancer-cells are {}.".format(solution))


if __name__ == '__main__':
    cancer(healthy_data, cancer_data, "Glucose [c]", endpoints)
