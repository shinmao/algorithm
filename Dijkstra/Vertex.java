package com.company;
import java.util.Comparator;

class Vertex implements Comparator<Vertex> {
    public int index, weight;

    public Vertex () {
    }

    public Vertex (int index, int weight) {
        this.index = index;
        this.weight = weight;
    }

    @Override
    public int compare(Vertex v1, Vertex v2) {
        if(v1.weight < v2.weight){
            return -1;
        }
        if(v1.weight > v2.weight){
            return 1;
        }
        return 0;
    }
}
