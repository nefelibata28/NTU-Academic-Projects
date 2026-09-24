
# SC4079 – Final Year Project 

# AI4VIS: AI-Powered Interactive Creation of Visualisations — Standard Charts


**Final Year Project | Nanyang Technological University**  
**College of Computing and Data Science**  
**Academic Year 2025/2026**  
 
**Author:** Bhati Nancy  
**Project Supervisor:** Ast/P Wang Yong  
**Examiner:** Prof Ong Yew Soon  
**Project Type:** Individual, Research-Based Final Year Project  
 
---
 
## Abstract
 
Large Language Models (LLMs) are increasingly being used to support data visualization and analysis through natural language interaction. These models have demonstrated growing capabilities in interpreting, generating, and reasoning over graphical information. However, their reliability and consistency across different visual and chart-related tasks present valuable opportunities for further exploration.
 
This project evaluates the performance of four contemporary LLMs — **ChatGPT (GPT-5.2)**, **Gemini (2.5 Flash)**, **Claude (Sonnet 4.5)**, and **Mistral (Large-2407)** — across a range of chart-related tasks. The evaluation focuses on three key areas: **visual encoding interpretation**, **chart-based question answering**, and **detection of misleading visualizations**. A category-based evaluation framework was developed to systematically assess model responses and identify recurring error patterns.
 
The study establishes baseline performance benchmarks for each model and provides a comparative analysis of their strengths and limitations, contributing to a deeper understanding of LLM reliability in real-world data analysis contexts.
 
---
 
## Table of Contents
 
- [Problem Statement](#problem-statement)
- [Objectives](#objectives)
- [Methodology](#methodology)
- [Evaluation Tasks](#evaluation-tasks)
- [Chart Categorization](#chart-categorization)
- [Evaluation Metrics](#evaluation-metrics)
- [Results Summary](#results-summary)
- [Key Findings](#key-findings)
- [Future Work](#future-work)
---
 
## Problem Statement
 
The reliability of LLMs in handling chart-related tasks remains an open research challenge. Limitations in this area may lead to incorrect interpretations, flawed insights, and the potential propagation of misleading information.
 
> **How well can LLMs actually understand and reason about charts?**
 
---
 
## Objectives
 
1. Evaluate and compare the performance of selected commercial and open-source LLMs across multiple chart-related task types.
2. Analyze common error patterns exhibited by LLMs when interpreting and reasoning about charts.
3. Identify the strengths and limitations of each evaluated LLM in handling graphical reasoning tasks.
---
 
## Methodology
 
The evaluation followed a six-stage pipeline:
 
| Stage | Description |
|---|---|
| 1. Selected LLMs | Selected multiple contemporary LLMs for comparative evaluation |
| 2. Tasks Design | Designed three evaluation tasks with specific objectives and criteria |
| 3. Data Collection | Collected a diverse set of standard charts for the defined tasks |
| 4. Charts Classification & Categorization | Categorized charts by type, task requirement, and complexity (common vs. advanced) |
| 5. Response Collection | Submitted charts to LLMs and collected generated responses |
| 6. Performance Evaluation & Analysis | Evaluated accuracy and analyzed performance using defined metrics |
 
### Selected LLMs
 
| LLM | Version / Model | Developer |
|---|---|---|
| ChatGPT | GPT-5.2 | OpenAI |
| Claude | Claude Sonnet 4.5 | Anthropic |
| Gemini | Gemini 2.5 Flash | Google |
| Mistral | Mistral-Large-2407 | Mistral AI |
 
Models were selected based on their popularity, accessibility, and claimed capabilities in data reasoning and analysis.
 
---
 
## Evaluation Tasks
 
### Task 1 — Visual Encoding Interpretation
Evaluates how accurately LLMs identify, understand, and reason about visual encoding elements (**color/hue, position, shape, length**) when interpreting charts.
 
### Task 2 — Chart-Based Question Answering
Evaluates analytical reasoning over chart images through structured question types:
- Highest / Lowest Value Identification
- Direct Value Retrieval
- Similarity Detection
- Ranking
- Difference Between Values
- Counting-Based Reasoning
  
### Task 3 — Detection of Misleading Charts
Evaluates the ability of LLMs to identify and explain flawed or misleading visualizations, across six flaw categories:
- Choice of Chart
- Color Mess
- Overplotting / Overcrowding
- Incorrect Size Encoding
- 3D Distortion
- Missing / Ambiguous Legend
---
 
## Chart Categorization
 
Charts were classified into two complexity tiers to enable comparative evaluation:
 
| Common Charts | Advanced Charts |
|---|---|
| Bar Chart | Radar Chart |
| Line Chart | Stream Graph |
| Histogram | Tidy Tree |
| Scatter Plot | Treemap |
| Pie Chart | Candlestick |
| Donut Chart | Sankey Diagram |
| Box Plot | Parallel Coordinates |
| Heatmap | Sunburst Chart |
| Stacked Area Chart | Geospatial Chart |
| Grouped / Stacked Bar Chart | Network Graph |
 
---
 
## Evaluation Metrics
 
- **Response Consistency** — A majority voting mechanism (5 trials per query) was used to select the most frequent response, mitigating randomness and hallucination effects.
- **Response Evaluation** — Each response was classified as:
  - ✅ **Correct** — fully matches the expected output
  - 🟣 **Partially Correct** — generally correct with minor errors or close to expected output
  - 🔴 **Incorrect** — significant errors in interpretation or reasoning
---
 
## Results Summary
 
### Overall Correct-Response Rate by Task
 
| LLM | Task 1 (Visual Encoding) | Task 2 (Question Answering) | Task 3 (Misleading Charts) |
|---|---|---|---|
| ChatGPT | 82.0% | 66.7% | 77.4% |
| Gemini | 81.0% | 74.0% | 79.9% |
| Claude | 76.2% | 56.9% | 79.0% |
| Mistral | 73.2% | 51.3% | 61.2% |
 
### Top Performers
 
| Task | Top Performer(s) |
|---|---|
| Task 1: Visual Encoding Interpretation | ChatGPT (82%), Gemini (81%) |
| Task 2: Chart-Based Question Answering | Gemini (74%) |
| Task 3: Detection of Misleading Charts | Gemini (79.9%), Claude (79%) |
 
---
 
## Key Findings
 
- **Gemini** was the most consistent top performer across all three tasks.
- **ChatGPT** demonstrated strong and stable performance across all categories.
- **Claude** and **Mistral** showed greater variability, particularly on reasoning-heavy tasks.
- All models performed **best on basic perception tasks** (Task 1: Visual Encoding Interpretation) and **worst on reasoning-intensive tasks** (Task 2: Chart-Based Question Answering).
- Results indicate persistent limitations in multi-step numerical and logical reasoning across LLMs, compared to their relatively stronger performance on visual encoding interpretation and misleading chart detection.
---

## Project Resources
 
| Resource | Description | Link |
|---|---|---|
| 📄 Final Year Project Report | Full write-up covering literature review, methodology, results, and discussion | [Report](https://github.com/nefelibata28/NTU-Academic-Projects/blob/main/Year4/SC4079/CCDS25_AI4VIS_FINAL_YEAR_PROJECT_REPORT.pdf) |
| 📊 Presentation Slides | Final presentation deck summarizing the project | [Slides](https://github.com/nefelibata28/NTU-Academic-Projects/blob/main/Year4/SC4079/FYP%20Presentation%20Slides.pdf) |
| 📈 Evaluation Spreadsheet | Structured record of all LLM interactions — includes prompts, responses, repetition counts, and final majority-vote answers, enabling systematic comparison across models, tasks, and chart categories | [Spreadsheet](https://entuedu-my.sharepoint.com/:x:/g/personal/nancy001_e_ntu_edu_sg/IQC4Suf-wL_ySI5v5zWc6oHtAVe1PByPz4ysEYOx5EMF6rg?e=hnm9VO) |
 
> Replace the `#` placeholders above with the actual links (e.g., Google Drive, OneDrive, or relative paths if the files are included in this repository).
---
 
## Future Work
 
1. **Expanded Evaluation** — Include more chart types, task categories, and datasets of varying complexity for better generalization.
2. **Improved Metrics** — Develop scoring methods that assess partial correctness, reasoning quality, and explanation clarity.
3. **Robust Testing** — Increase test cases and add complex/adversarial scenarios to better probe model limits.
4. **Prompt Engineering** — Design structured, step-by-step prompts to improve accuracy, consistency, and reduce hallucinations in visualization tasks.
---

## Citation
 
This project is officially archived in NTU's Digital Repository (DR-NTU):
 
**DR-NTU Record:** [https://dr.ntu.edu.sg/entities/publication/b02fd3a6-1cbe-4e3e-8fb8-d05543a4a39b](https://dr.ntu.edu.sg/entities/publication/b02fd3a6-1cbe-4e3e-8fb8-d05543a4a39b)
 
If referencing this work, please cite it as:
 
> Bhati, N. (2026). *AI4VIS: AI-Powered Interactive Creation of Visualisations - Standard Charts* [Final Year Project Report, Nanyang Technological University]. DR-NTU. https://dr.ntu.edu.sg/entities/publication/b02fd3a6-1cbe-4e3e-8fb8-d05543a4a39b
 
---

## Acknowledgements
 
This project was completed as part of the Final Year Project requirement for the Degree of Bachelor of Computing in Computer Science at Nanyang Technological University (NTU). Special thanks to Project Supervisor **Ast/P Wang Yong** and Examiner **Prof Ong Yew Soon** for their guidance throughout the project.
 
---
 
## License
 
This project is submitted for academic purposes as part of the NTU Final Year Project requirements. Please contact the author for reuse or citation permissions.
 

