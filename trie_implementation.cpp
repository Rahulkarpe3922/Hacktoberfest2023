

struct TrieNode{
    char c;
    int count;
    int endshere;
    TrieNode* child[26];
    TrieNode(int cf){
        c='a'+cf;
        count=endshere=0;
        for(int i=0;i<26;i++){
            child[i]=NULL;
            
        }
        //here inside the construtor we are initialising a trienode data struture

    
    }
};


class WordDictionary {
public:
    TrieNode* root;

    map<string,int>mp;
    WordDictionary() {
        root=new TrieNode('/');

        
    }
    void insert(string & word){


        TrieNode* curr=root;
        int c=0;
        //first understand the logic and then code it well
        for(int i=0;i<word.size();i++){
            if(curr->child[word[i]-'a']==NULL){
                curr->child[word[i]-'a']=new TrieNode(word[i]-'a');

            }
            curr=curr->child[word[i]-'a'];

        }
        curr->endshere=1;
    }
    
    void addWord(string word) {
      insert(word);
        
    }


   
    void searcht(string & word,int idx,TrieNode* t,bool &ans){


        //now we have made this function as a recursive one
        
        if(idx==word.size()){
            if(t->endshere){
                ans=true;
            }
            return ;
        }
    
   
            if(word[idx]!='.'){
                if(t->child[word[idx]-'a']!=NULL){
                    searcht(word,idx+1,t->child[word[idx]-'a'],ans);

                }else{
                    return ;
                }
                
            }else{
                for(int i=0;i<26;i++){
                    if(t->child[i]!=NULL){
                        searcht(word,idx+1,t->child[i],ans);
                    }
                }
            }
        
    }


      
    
    
    bool search(string word) {
        //this searching word might contains dots 
        //is ke all possible combination we need to check 
        //first convert word into a char 
        //avoid using extra space if it can be done without it 
        //always try to write clean code as much as possible



        
        bool ans=false;
        // help(word,"",0,ans);
        TrieNode* r=root;
        searcht(word,0,r,ans);

        return ans;

        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
