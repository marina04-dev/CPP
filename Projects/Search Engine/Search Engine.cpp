#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<unordered_map>

using namespace std; // allows usage of standard C++ library without std:: prefix

// title|content|category|date: the file's structure 

// Structure to store each document's information
struct Document {
    int id; // Unique identifier for each document
    string title; // Title of the document
    string content; // Main content/text of the document
    string category; // Category of the document
    string date; // Date associated with the document
};

// Class to manage the inverted index (maps keywords to document IDs)
class InvertedIndex {
    public:
        void addDocument(const Document &doc); // Adds document to the index
        vector<int> search(const string &keyword); // Returns list of document IDs matching the keyword
    private:
        unordered_map<string,vector<int>> index; // Hash map from keyword to list of document IDs
};

// Class to manage the entire search engine
class SearchEngine {
    public:
        void loadDocuments(const string&filePath); // Loads documents from a file
        vector<Document> search(const string&keyword,const string&category="",const string&date=""); // Searches documents
    private:
        vector<Document> documents; // Stores all documents loaded into memory
        InvertedIndex index; // Instance of the inverted index
};


// Main function to demonstrate functionality
int main() {
    SearchEngine engine;
    engine.loadDocuments("data.txt"); // Load documents from file named data.txt

    string keyword;
    cout<<"Enter keyword to search: ";
    cin>>keyword; // Get keyword from user

    vector<Document>results=engine.search(keyword); // Perform search
    for(const Document&doc:results) {
        cout<<"ID: "<<doc.id<<" | Title: "<<doc.title<<" | Category: "<<doc.category<<" | Date: "<<doc.date<<endl;
    }

    return 0;
}



// Implementation of InvertedIndex::addDocument
void InvertedIndex::addDocument(const Document&doc) {
    istringstream iss(doc.content); // Create stream to split content into words
    string word;
    while(iss>>word) { // Extract each word
        index[word].push_back(doc.id); // Map word to document ID
    }
}

// Implementation of InvertedIndex::search
vector<int> InvertedIndex::search(const string&keyword) {
    if(index.find(keyword)!=index.end()) {
        return index[keyword]; // Return matching document IDs
    }
    return {}; // Return empty list if no match
}

// Implementation of SearchEngine::loadDocuments
void SearchEngine::loadDocuments(const string&filePath) {
    ifstream file(filePath); // Open file for reading
    if(!file) {
        cerr<<"Error opening file."<<endl;
        return;
    }

    string line;
    while(getline(file,line)) { // Read each line as one document
        istringstream iss(line);
        Document doc;
        getline(iss,doc.title,'|'); // Extract title until '|'
        getline(iss,doc.content,'|'); // Extract content until '|'
        getline(iss,doc.category,'|'); // Extract category until '|'
        getline(iss,doc.date,'|'); // Extract date until '|'
        doc.id=documents.size(); // Assign a unique ID

        documents.push_back(doc); // Add to documents list
        index.addDocument(doc); // Index this document
    }
}

// Implementation of SearchEngine::search
vector<Document> SearchEngine::search(const string&keyword,const string&category,const string&date) {
    vector<int>docIds=index.search(keyword); // Get document IDs from index
    vector<Document>results;
    for(int id:docIds) {
        Document doc=documents[id];
        if((category.empty()||doc.category==category)&&
           (date.empty()||doc.date==date)) {
            results.push_back(doc); // Filter by category and date if given
        }
    }
    return results;
}


