#include <iostream>
#include <vector>
#include <linked_list.hpp> 
#include <graph.hpp> 
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <search.hpp>
#include <bst.hpp>

#ifdef OPENCV
#include <opencv2/opencv.hpp>
#endif

bool testBST() {
    BST bst;
    for (int i = 0; i <= 9; ++i) {
        std::cout << "Insert " << i << " into BST. "; 
        bst.insert(i);

        std::cout << "Find " << i << ": ";  
        if (bst.find(i) != NULL && bst.find(i)->key == i)
            std::cout << "Found " << i << " in BST. ";
        else {
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Insert or Find Method in BST is Incorrect.\n");
        }

        
        std::cout << "Find " << i+1 << ": ";  
        if (bst.find(i+1) == NULL)
            std::cout << "Not found " << i+1 << " in BST" << std::endl;
        else {
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Insert or Find Method in BST is Incorrect.\n");
        }

    }

    std::cout << "Insert 9 into BST." << std::endl;
    bst.insert(9);

    std::cout << "Maximum value in BST: ";
    BSTNode *node = bst.popMaximum();

    if (node == NULL || node->key != 9)
        throw std::invalid_argument("\n[ERROR MESSAGE]. Your Pop Maximum Method in BST is Incorrect.\n");
    else
        std::cout << node->key << ". ";
    delete node;

    std::cout << "Find 9: ";  
    if (bst.find(9) != NULL)
        std::cout << "Found 9 in BST (We have two values of 9 in BST)" << std::endl;
    else {
        throw std::invalid_argument("\n[ERROR MESSAGE]. Your Pop Maximum or Find Method in BST is Incorrect.\n");
    }

    
    std::cout << "Mininum value in BST: ";
    node = bst.popMinimum();

    if (node == NULL || node->key != 0)
        throw std::invalid_argument("\n[ERROR MESSAGE]. Your Pop Minimum Method in BST is Incorrect.\n");
    else
        std::cout << node->key << ". "; 
    delete node;
    
    std::cout << "Find 0: ";  
    if (bst.find(0) == NULL)
        std::cout << "Not found 0 in BST" << std::endl;
    else {
        throw std::invalid_argument("\n[ERROR MESSAGE]. Your Pop Maximum or Find Method in BST is Incorrect.\n");
    }

    
    for (int i = 1; i <= 8; ++i) {
        std::cout << "Remove " << i << " out of BST. ";
        bst.remove(i);

        std::cout << "Find " << i << ": ";  
        if (bst.find(i) == NULL) 
            std::cout << "Not found " << i << " in BST. ";
        else
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Remove or Find Method in BST is Incorrect.\n");


        std::cout << "Find " << i+1 << ": ";  
        if (bst.find(i+1) != NULL && bst.find(i+1)->key == i+1)
            std::cout << "Found " << i+1 << " in BST" << std::endl;
        else
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Remove or Find Method in BST is Incorrect.\n");
    }
    
    std::cout << "Remove 9 out of BST. "; 
    bst.remove(9);
    std::cout << "Find " << 9 << ": ";  
    if (bst.find(9) == NULL) 
        std::cout << "Not found 9 in BST" << std::endl;
    else
        throw std::invalid_argument("\n[ERROR MESSAGE]. Your Remove or Find Method in BST is Incorrect.\n");


    return true;
}

#ifdef GRADUATE

#include <avl.hpp> 

bool testAVL() {
    AVL bst;
    for (int i = 0; i <= 9; ++i) {
        std::cout << "Insert " << i << " into AVL. ";
        bst.insert(i);

        std::cout << "Find " << i << ": ";  
        if (bst.find(i) != NULL && bst.find(i)->key == i)
            std::cout << "Found " << i << " in AVL. ";
        else {
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Insert or Find Method (Find Method is called from the base class) in AVL is Incorrect.\n");
        }

        
        std::cout << "Find " << i+1 << ": ";  
        if (bst.find(i+1) == NULL)
            std::cout << "Not found " << i+1 << " in AVL" << std::endl;
        else {
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Insert or Find Method (Find Method is called from the base class) in AVL is Incorrect.\n");
        }

    }

    
    for (int i = 0; i <= 8; ++i) {
        std::cout << "Remove " << i << " out of AVL. ";
        bst.remove(i);

        std::cout << "Find " << i << ": ";  
        if (bst.find(i) == NULL) 
            std::cout << "Not found " << i << " in BST. ";
        else
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Remove or Find Method (Find Method is called from the base class) in AVL is Incorrect.\n");


        std::cout << "Find " << i+1 << ": ";  
        if (bst.find(i+1) != NULL && bst.find(i+1)->key == i+1)
            std::cout << "Found " << i+1 << " in BST" << std::endl;
        else
            throw std::invalid_argument("\n[ERROR MESSAGE]. Your Remove or Find Method (Find Method is called from the base class) in AVL is Incorrect.\n");
    }
    
    std::cout << "Remove 9 out of BST. ";
    bst.remove(9);
    std::cout << "Find 9: ";  
    if (bst.find(9) == NULL) 
        std::cout << "Not found 9 in BST" << std::endl;
    else
        throw std::invalid_argument("\n[ERROR MESSAGE]. Your Remove or Find Method (Find Method is called from the base class) in AVL is Incorrect.\n");

    return true;
}

#endif  

bool testGraph() {
    Graph G(6);
    G.insertEdge(0, 1, 1);
    G.insertEdge(1, 2, 2);
    G.insertEdge(1, 3, 3);
    G.insertEdge(2, 4, 4);
    G.insertEdge(4, 3, 5);
    G.insertEdge(4, 5, 6);


    std::cout << "Shortest path from 0 to 5 by " << ": " ;
    std::vector<int> path = G.search(0, 5, bfs);
    for (int i = 0; i < path.size(); ++i) 
        std::cout << path[i] << " ";
    std::cout << "\n";
    std::cout << "Total Distance: " << G.distance(5) << std::endl;
    
    return true;
}

#ifdef OPENCV
void drawDashedLine(cv::Mat& img, cv::Point pt1, cv::Point pt2,
                    cv::Scalar color, int thickness, std::string style,
                    int gap) {
  float dx = pt1.x - pt2.x;
  float dy = pt1.y - pt2.y;
  float dist = std::hypot(dx, dy);

  std::vector<cv::Point> pts;
  for (int i = 0; i < dist; i += gap) {
    float r = static_cast<float>(i / dist);
    int x = static_cast<int>((pt1.x * (1.0 - r) + pt2.x * r) + .5);
    int y = static_cast<int>((pt1.y * (1.0 - r) + pt2.y * r) + .5);
    pts.emplace_back(x, y);
  }

  int pts_size = pts.size();

  if (style == "dotted") {
    for (int i = 0; i < pts_size; ++i) {
      cv::circle(img, pts[i], thickness, color, -1);
    }
  } else {
    cv::Point s = pts[0];
    cv::Point e = pts[0];

    for (int i = 0; i < pts_size; ++i) {
      s = e;
      e = pts[i];
      if (i % 2 == 1) {
        cv::line(img, s, e, color, thickness);
      }
    }
  }
}
#endif

void searchOnCampus(std::string start = "BELL", std::string destination = "HAPG") {
    std::ifstream reader("assets/map_info.txt");
    int n, m;
    reader >> n >> m;
    std::map<std::string, int> name2index;
    std::map<int, std::string> index2name;
    std::vector<int> xs;
    std::vector<int> ys;
    for (int i = 0; i < n; ++i) {
        int index, x, y;
        std::string name;
        reader >> index >> name >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        name2index[name] = index;
        index2name[index] = name;
    }

    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        reader >> u >> v;
        int dx = xs[u] - xs[v];
        int dy = ys[u] - ys[v];
        int w = (int)sqrt(dx * dx + dy * dy);
        G.insertEdge(u, v, w);
    }

    std::vector<int> path = G.search(name2index[start], name2index[destination], bfs);

    std::cout << "Shorest path from " << start  << " to " << " detination: " << start ;
    for (int i = 1; i < path.size(); ++i)
        std::cout << " -> " << index2name[path[i]];
    
    std::cout << "\n";
    
    std::cout << "Total Distance: " << G.distance(name2index[destination]) << std::endl;

#ifdef OPENCV
    cv::Mat image = cv::imread("assets/map.png");
    for (int i = 0; i < n; ++i) {
        cv::circle(image, cv::Point(xs[i], ys[i]), 5, cv::Scalar(255, 0, 0), -1);
        if (index2name[i] == start || index2name[i] == destination)
            cv::putText(image, index2name[i],  cv::Point(xs[i], ys[i]-10),  cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255, 0, 0), 2);
        
    }
    
    for (int u = 0; u < n; ++u) {
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<std::pair<int, int> > *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value.first;
            drawDashedLine(image, cv::Point(xs[u], ys[u]), cv::Point(xs[v], ys[v]), cv::Scalar(0, 0, 255), 1, "", 5);
        }
    }
    cv::Mat oriImage = image.clone();
    std::cout << "Press esc or Ctrl + C to stop the program" << std::endl;
    while (true) {
        image = oriImage.clone();
        for (int i = 0; i < path.size(); ++i) {
            if (i > 0) 
                cv::line(image, cv::Point(xs[path[i]], ys[path[i]]), cv::Point(xs[path[i-1]], ys[path[i-1]]), cv::Scalar(0, 255, 0), 4);
            cv::imshow("Shorest path from " + start + " to " + destination + " (Press esc to exit).", image);
            int time;
            if (i+1 == path.size())
                time = 2000;
            else
                time = 400;
            if (cv::waitKey(time) == 27)
                break;
        }
    }

#else
    std::cout << "You have to use OpenCV to visualize your map road\n";
#endif


}
int main(int argc, char **args) {

    std::cout << std::endl;
    try {
        std::cout << "Perform unit test on your BST implementation" << std::endl;
        if (testBST())
            std::cout << "Your BST implementation is correct" << std::endl;
        else {
            std::cout << "Your BST implementation is incorrect" << std::endl;
            return -1;
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what();
        return -1;
    }

#ifdef GRADUATE
    try {
        std::cout << std::endl;
        std::cout << "Perform unit test on your AVL implementation" << std::endl;
        if (testAVL())
            std::cout << "Your AVL implementation is correct" << std::endl;
        else {
            std::cout << "Your AVL implementation is incorrect" << std::endl;
            return -1;
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what();
    }

#endif


    std::cout << std::endl;
    std::cout << "Perform unit test on your implementation with graph" << std::endl;
    testGraph();
    
    std::cout << std::endl;
    searchOnCampus("RSWE", "GEAR");
    
}
