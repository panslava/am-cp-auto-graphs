all: articulation_points mst_directed strongly_connected ford_bellman dijkstra kruskal min-cut min-cost_max-flow

create_dir:
	mkdir -p built

clean:
	rm -rf built/*

articulation_points: create_dir
	g++ -std=c++17 -O3 articulation_points.cpp -o built/articulation_points

mst_directed: create_dir
	g++ -std=c++17 -O3 mst_directed.cpp -o built/mst_directed

strongly_connected: create_dir
	g++ -std=c++17 -O3 strongly_connected.cpp -o built/strongly_connected

ford_bellman: create_dir
	g++ -std=c++17 -w -O3 ford_bellman.cpp -o built/ford_bellman

dijkstra: create_dir
	g++ -std=c++17 -w -O3 dijkstra.cpp -o built/dijkstra

kruskal: create_dir
	g++ -std=c++17 -w -O3 kruskal.cpp -o built/kruskal

min-cut: create_dir
	g++ -std=c++17 -w -O3 min-cut.cpp -o built/min-cut

min-cost_max-flow: create_dir
	g++ -std=c++17 -w -O3 min-cost_max-flow.cpp -o built/min-cost_max-flow