# SC3020 – Database System Principles

This folder includes two major projects for the module **SC3020 – Database System Principles**,  with implementation code, demo videos, and written reports.

## Module Overview

SC3020 introduces fundamental principles of database systems, covering relational models, SQL, database design, query processing and optimisation, indexing, and transaction management. 

## Project Highlights

| Project 1 | Project 2 |
|-----------|-----------|
| - Designed and implemented a storage component for a database using a slotted-page heap file <br> - Built a B+ tree indexing component on top of the storage for fast retrieval and deletion <br> - Performed bulk loading, deletion, and query optimization using the B+ tree <br> - Achieved improved query performance over brute-force scanning | - Practical exploration of query optimization techniques in PostgreSQL <br> - Hands-on experience with concurrency control and transaction isolation levels <br> - Use of TPC-H benchmark-style datasets to simulate real-world database operations <br> - Analysis of execution plans, indexing strategies, and memory management impacts |

## Project Deliverables (Group Project)
| Project 1 | Project 2 |
|-----------|-----------|
| -  [Project Presentation Video with Demo](https://drive.google.com/file/d/1RCOyaE4KIcApjiW6kEtItv94ioLftM_z/view?usp=sharing) <br> - [Project Report](https://drive.google.com/file/d/1bE02snDvJxGLSowl9Gd9uyLFbWoH-TDY/view?usp=sharing) <br> - [Project Code](https://github.com/kumo-ing/SC3020) | -  [Project Report](https://drive.google.com/file/d/146qmzb4o6hKYkh7w1qZo94jZmkk7waqt/view?usp=sharing)|


## Projects
The following are the projects for this module. All projects are *group-based*:

## Project 1 - Storage and Indexing Implementation
This project is to design and implement the two components of a database management system, storage and indexing on the given dataset.

1. Storage Component: Efficiently store records on disk using a slotted-page structure.
2. Indexing Component: Build a B+ tree index on the attribute FT_PCT_home to enable fast queries and deletions.

The system supports loading data from a file, building an index, executing range queries, and performing deletions while maintaining data consistency.

[Project Instructions](https://drive.google.com/file/d/1T0ksCibKDVXnFArK8vEhajejOHUvOgDr/view?usp=sharing)

## Objectives
- Design a storage system that organizes data into pages/blocks on disk.
- Implement a B+ tree for indexing with support for duplicates, dynamic growth/shrinkage, and bulk loading.
- Compare index-based queries against brute-force linear scans to demonstrate efficiency gains.
- Execute deletion operations using the index while maintaining heap and B+ tree consistency.

## Dataset Overview
[NBA team Dataset](https://www.dropbox.com/scl/fi/s4wgb8uspaq1bog6tbyby/games.txt?rlkey=gmc0i28bs53mmxovcewpc4mlx&e=1&dl=0) 
<img width="640" height="323" alt="image" src="https://github.com/user-attachments/assets/c821468e-e543-45a4-8273-b400fb3bd324" />


## Project Deliverables
-  [Project Presentation Video with Demo](https://drive.google.com/file/d/1RCOyaE4KIcApjiW6kEtItv94ioLftM_z/view?usp=sharing)
-  [Project Report](https://drive.google.com/file/d/1bE02snDvJxGLSowl9Gd9uyLFbWoH-TDY/view?usp=sharing)
-  [Code](https://github.com/kumo-ing/SC3020)

## Methodology
### 1. Storage Component (Task 1)
- Records are stored in pages of 4096 bytes, each with a PageHeader and SlotEntries.
- Records grow upward, slot directory grows downward.
- Insertions check available space (ensureSpace()) and allocate new pages if needed.
- Result: 26,552 records stored across 296 pages, with 90 records per page.
<img width="400" alt="image" src="https://github.com/user-attachments/assets/e5ef288a-59b8-40b1-8b79-d16d01ac75dd" />


### 2. B+ Tree Indexing (Task 2)
- Key: FT_PCT_home
- Order (n): 30 (max keys per node)
- Leaf nodes: Store all record pointers (RIDs) for duplicates.
- Bulk loading:
    -  Group duplicates by FT_PCT_home.
    - Pack leaf nodes and iteratively build parent nodes.
    - Achieve a 2-level tree with 14 leaf nodes and 1 root node.
- Supports insertion, overflow handling (split & promotion), and dynamic rebalancing.
 <img width="400" alt="image" src="https://github.com/user-attachments/assets/3d350af2-42aa-40d3-81a6-6a5a4c0fff73" /> <img width="500"  alt="image" src="https://github.com/user-attachments/assets/d43cdb5d-b32e-4aee-842e-5f7edabee866" />


### 3. Deletion and Query (Task 3)
- Deletes all games with FT_PCT_home > 0.9.
- Uses index-based retrieval for efficiency; marks records as deleted in heap.
- B+ tree adjusts nodes via borrowing or merging when underflow occurs.
- Instrumentation captured: nodes accessed, data blocks accessed, number of games deleted, retrieval time.

  <img width="400"  alt="image" src="https://github.com/user-attachments/assets/75e59541-f6cb-4394-9f41-a565462735ed" /> <img width="500" h alt="image" src="https://github.com/user-attachments/assets/1c0c2f19-e28e-4f4d-9a88-f16f720efebd" />

---

## Project 2 - Query Optimization and Concurrency Control in PostgreSQL
This project is designed to deepen the understanding of query optimization and concurrency control through authentic experience on a real database system.

[Project Instructions](https://github.com/nefelibata28/NTU-Academic-Projects/blob/main/Year4/SC3020/Project%201%20Instructions.pdf)

## Objectives
- Understand PostgreSQL query planner decisions and execution strategies.
- Learn to optimize queries using indexes and memory configuration.
- Examine the impact of working memory on aggregation, joins, and sorting.
- Investigate transaction isolation levels and concurrency anomalies.

## Dataset Overview
- The dataset consists of 8 CSV files based on the TPC-H benchmark.
- Contains tables such as customer, lineitem, orders, part, supplier, region, nation, and partsupp.
- Foreign keys and primary keys are properly defined, with default B+ tree indexes created on primary keys
 [Project Dataset](https://drive.google.com/file/d/1CWSO6VBVmtVJLLF7XW3To3NIQYF98eeY/view?usp=sharing)

## Project Deliverables
-  [Project Report](https://github.com/nefelibata28/NTU-Academic-Projects/blob/main/Year4/SC3020/Project%201%20Report.pdf)

## Methodology
### 1. Database Setup
- Installed PostgreSQL and pgAdmin4 on Windows.
- Created the database and imported CSV files into 9 tables.

### 2. Query Optimization Tasks
- Used EXPLAIN and EXPLAIN ANALYZE to inspect query plans.
- Tested sequential scans, bitmap scans, hash joins, merge joins, and aggregation.
- Experimented with index creation, hash indexes, and work_mem configurations to observe performance changes.
  
<img width="606" height="46" alt="image" src="https://github.com/user-attachments/assets/4b8eddaa-b409-4324-96e7-ef4545349b84" />

<img width="500" alt="image" src="https://github.com/user-attachments/assets/597fe5fb-6068-42c0-b67e-af45f9d25237" />

### 3. Transaction Tasks
- Executed transactions at READ COMMITTED and SERIALIZABLE isolation levels.
- Observed anomalies like phantoms and write-skew, explaining why PostgreSQL behaves this way.

### 4. Performance Analysis
- Compared query runtimes under different scenarios.
- Identified optimization strategies like pre-aggregation to reduce combinatorial overhead.

## Tools Used
- Project 1
  - VS Code : C++
  - Data Structures: Heap file, B+ tree
- Project 2
  - PostgreSQL : Database engine for query execution and transaction handling.
  - pgAdmin : Used to write, execute, and test SQL queries in PostgreSQL
- Canva (Presentation)
- MS Word (Report)

## Notes
- All assignments are submitted as part of NTU's official coursework.
- Files may include assignment descriptions.
- Please do not plagiarize; this repository is for learning/reference only.















