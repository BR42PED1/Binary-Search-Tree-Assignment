//***********************************************************************************
// CSCI 3333.03 Spring 2023
// Instructor: Dr. Andres Figueroa
// Programming Assignment 2: Movies Dataset using BST
// Students Name and SID#:
//
//***********************************************************************************

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

using namespace std;


int main()
{
    BinarySearchTree bst;
    Node* current = NULL;

    ifstream movies("movies.txt"); //open and read txt file
    string line;
    string rest;
    string id;
    string title;
    string region;
    int pos = 0;

    if (!movies.is_open())
    {
        cout << "Unable to open file";
        system("pause");
        exit(1);
    }
    while (getline(movies, line))
    {
  // string line must be a tab delimited line in the format:"id<tab>title<tab>region"
  pos = line.find('\t');
  id = line.substr(0,pos); //get the first pos characters from line
  rest = line.substr(pos+1); //copy the rest of the string from position pos
  pos = rest.find('\t');
  title = rest.substr(0,pos); //get the first pos characters from rest 
  region = rest.substr(pos+1, 2); //get the following two characters from position pos+1 
  //cout << "Inserting: " << id << "\t\t" << title << "\t\t" << region << endl; 
        bst.insert(id, title, region);
    }

    cout << "\n\nPrinting BST in order:\n";
    bst.inOrder();
    cout << "\n\nThe number of elements in BST is: ";
    cout << bst.size() << endl;

    cout << "Searching for the following movies:\n";
    string key = "Nightbeast";
    if ( (current = bst.search(key)) != NULL )
    {
          cout<< "Movie \""<< key << "\" was found." << endl;
    if ( current->left != NULL )
      cout<<"Movie at the left is: "<< current->left->movieTitle << endl;
    else
      cout << "Left child is NULL" << endl;
    if (current->right != NULL )
      cout<<"Mmovie at the right is: "<< current->right->movieTitle << endl;
    else 
      cout << "Right child is NULL" << endl;
    }
    else{
    cout<< "Movie \""<< key << "\" was not found." << endl;
    }
    key = "El alcalde Lagos";
    if ( (current = bst.search(key)) != NULL )
    {
                cout<< "Movie \""<< key << "\" was found." << endl;
                if ( current->left != NULL )
                        cout<<"Movie at the left is: "<< current->left->movieTitle << endl;
    else
      cout << "Left child is NULL" << endl;
                if (current->right != NULL )
                        cout<<"Movie at the right is: "<< current->right->movieTitle << endl;
    else 
      cout << "Right child is NULL" << endl;
    }
    else{
              cout<< "Movie \""<< key << "\" was not found." << endl;
    }
    key = "Entre tontos y astutos";
    if ( (current = bst.search(key)) != NULL )
    {
                cout<< "Movie \""<< key << "\" was found." << endl;
                if ( current->left != NULL )
                        cout<<"Movie at the left is: "<< current->left->movieTitle << endl;
    else
      cout << "Left child is NULL" << endl;
                if (current->right != NULL )
                        cout<<"Movie at the right is: "<< current->right->movieTitle << endl;
    else 
      cout << "Right child is NULL" << endl;
    }
    else{
                cout<< "Movie \""<< key << "\" was not found." << endl;
    }
    key = "Scared of Guns";
    if ( (current = bst.search(key)) != NULL )
    {
                cout<< "Movie \""<< key << "\" was found." << endl;
                if ( current->left != NULL )
                        cout<<"Movie at the left is: "<< current->left->movieTitle << endl;
    else
      cout << "Left child is NULL" << endl;
                if (current->right != NULL )
                        cout<<"Movie at the right is: "<< current->right->movieTitle << endl;
    else 
      cout << "Right child is NULL" << endl;
    }
    else{
                cout<< "Movie \""<< key << "\" was not found." << endl;
    }


    return 0;
}