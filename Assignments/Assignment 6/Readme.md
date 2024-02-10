# Assignment 6: Some final questions

## Objectives
* identify situations where methods can be applied across different application areas
* critically discuss problems and methods in computational bioinformatics

## Exercises
1. Give four examples of the application simulated annealing: two in bioinformatics (at least one of which should not have been described in the course lectures) and two examples in another area (not related to bioinformatics). For each example, briefly describe (i) how solutions are generated and (ii) how solutions are scored.

2. On page 972 of the article by Morris et al. (2002) the authors state: "The presence of cis-peptides adds an extra complication that we have chosen to ignore". Discuss this "complication", and why the authors chose to ignore it.

3. On page 219 of the article by Simons et al. (1997) the authors state: "the similarity in topology is clear ... in the contact map (Figure 9B)". Explain what the authors mean by this.

4. 
    1. Discuss how the concept of mesostates (as described by Gong et al. (2005), or Chellapa and Rose (2012)) could be used in performing structural alignment.

        Briefly discuss any advantages or disadvantages of this approach to structural alignment, compared with one published method for structural alignment (e.g. Taylor and Orengo, 1989; Holm and Sander, 1996; Zhu and Weng, 2005).

    2. When a chatbot (like ChatGPT) was asked to answer part (a), its response included the following:
        ```
        "By considering the flexibility and conformational variations of proteins, the concept of mesostates has been put out as a technique to enhance structural alignment. Mesostates are used in the MESODOCK approach, developed by Gong et al. (2005), to achieve structural alignment while taking into account all possible protein conformations as opposed to simply one static structure. When aligning proteins that experience considerable conformational changes, such as enzymes that significantly alter their conformation upon substrate binding, this method can be especially helpful.

        Reference

        Gong, Y., Rose, P. W., & Cowburn, D. (2005). MESODOCK: a structural alignment algorithm that integrates the structural flexibility of proteins. Bioinformatics, 21(6), 803-809."
        ```
        Discuss whether this response is accurate or useful.

5. Schenk et al. (2008) chose to use PDB entry 1KCT in their work since it was found to have "less than 7 % annotated α-helix or β-strand". However, the paper describing the protein α1-antitrypsin (Song et al. 1995) shows that this protein has nine α-helices and extensive β-sheets. Thus, these papers have different views about the secondary structure content of α1-antitrypsin. Explain why 1KCT was identified as an example of a protein with a very low amount of secondary structure.

6. When protein-ligand docking predictions are evaluated by comparing with a structure obtained by x.ray crystallography, "the RMSD cutoff of of 2 Å is often used as a criterion of the correct bound structure prediction" (Trott and Olson, 2009).

    Describe how the coordinates of the atoms of the protein and the ligand of the predicted complex and those of the crystallographic structure can be used to calculate the RMSD. If you foresee cases where this approach would give an RMSD error that does not reflect fairly the quality of the docking prediction, give an example of such a case. (Depending on your answer to the first part of this question, there might not be any such cases.)
