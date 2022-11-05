#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
//Code created by Leonardo Magallanes
/* Transaction data
* Block class
* Blokchain*/

struct TransactionData {
	double amount;
	string senderKey;
	string receiverKey;
	time_t timeStamp; //To keep track at what time the transaction was made
};

class Block{
private:
	int index;
	size_t blockHash;//size_t is an unsigned integer. Is what gets returned when you use the generateHash function
	size_t previousHash;
	size_t generateHash();
public:
	TransactionData data;
	Block(int, TransactionData, size_t);
	size_t getHash() { return blockHash; };
	size_t getPreviousHash() { return previousHash; };
	bool isHashValid();

};

Block::Block(int index, TransactionData data, size_t previousHash){
	this->index = index;
	this->data = data;
	this->previousHash = previousHash;
	blockHash = generateHash();
}
size_t Block::generateHash() {
	hash<string> hash1;
	hash<size_t> hash2;
	hash<size_t> finalHash;
	string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timeStamp);//Concatenate the Transaction data.
	return finalHash(hash1(toHash) + hash2(previousHash)); //The hash return depends on the transaction data and the previous hash.
}
bool Block::isHashValid() {
	return generateHash() == blockHash; //To know if someone manipulated data.
}


class BlockChain{
private:
	Block createFirstBlock();
public:
	vector<Block> chain; //Our public chain
	BlockChain();
	void addBlock(TransactionData data);
	bool isChainValid();
	Block* getLatestBlock();//This function will return a pointer to a Block, we will use this if we want to modify the data inside a block
};

BlockChain::BlockChain(){//default constructor
	Block genesis = createFirstBlock();
	chain.push_back(genesis);//add the first block into the blockchain
}
Block BlockChain::createFirstBlock(){//This will be the first block in the chain.
	//the block constructor takes index, transaction data and previous hash. line 34.
	time_t current;
	TransactionData data;
	data.amount = 0;
	data.receiverKey = "None";
	data.senderKey = "None";
	data.timeStamp = time(&current); //Get the current time

	hash<int> hash1;
	Block genesis(0, data, hash1(0));
	return genesis;//return the first block
}
Block* BlockChain::getLatestBlock() {
	return &chain.back();//Returning the memory address of the last block.
}
void BlockChain::addBlock(TransactionData data) {
	int index = (int)chain.size() - 1;
	Block newBlock(index, data, getLatestBlock()->getHash()); //3rd parameter: Get the previous hash. We use the -> operator because we getLatestBlock() return a pointer.
}
bool BlockChain::isChainValid() {
	vector<Block>::iterator it;
	int chainLen = (int)chain.size();

	for (it = chain.begin(); it != chain.end(); it++) {
		Block currentBlock = *it; //Pointer to our current block.
		if (!currentBlock.isHashValid()) return false; 
		
		if (chainLen > 1) {
			Block previousBlock = *(it - 1);//We point to the previous block.
			if (currentBlock.getPreviousHash() != previousBlock.getHash()) { //If the hash of the previous and the current doesn't match then is false.
				return false;
			}
		}
	}
	return true;
}


int main() { 
	/*time_t current;
	cout << time(&current);*/
	BlockChain MAGA;

	//Data for first added Block
	TransactionData data1;
	time_t dataTime;
	data1.amount = 1;
	data1.receiverKey = "Someone";
	data1.senderKey = "Leonardo";
	data1.timeStamp = time(&dataTime);

	MAGA.addBlock(data1);

	cout << "Is chain valid?\n";
	if (MAGA.isChainValid()) cout << "Yes it is valid\n\nCongratulations you have created the first token/coin! :)\n";
	else cout << "No it isn't valid\n";
	cout << data1.timeStamp << "\n";

	return 0; 
}