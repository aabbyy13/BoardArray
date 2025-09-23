#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }



    void add(Entry* entry) {
            int insertIndex = -1;

            for (int i = 0; i < index; ++i) {
                if (entry->compare(&array[i])) {
                    insertIndex = i;
                    break;
                }
            }

            if (insertIndex == -1) {
                insertIndex = index;
            }

            if (index < SIZE) {
                for (int j = index; j > insertIndex; --j) {
                    array[j] = array[j - 1];
                }
                array[insertIndex] = *entry;
                ++index;
            } else {
                if (insertIndex == SIZE) {
                    std::cout << entry->name << "'s score is too low to be added!" << std::endl;
                } else {
                    for (int j = SIZE - 1; j > insertIndex; --j) {
                        array[j] = array[j - 1];
                    }
                    array[insertIndex] = *entry;
                }
            }
        }


        // TODO: IMPLEMENT THIS FUNCTION
        // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT



        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};