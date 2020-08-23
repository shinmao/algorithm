int search(const ArrayReader& reader, int target) {
    if(target >= 10000 || target <= -10000) return -1;
    int start = 0, end = 1, mid;
    while(reader.get(end) < target) {
        start = end;
        end = end << 1;
    }
    while(start <= end) {
        mid = (start + end) >> 1;
        if(reader.get(mid) >= 10000) end = end/2;
        if(reader.get(mid) == target) return mid;
        if(reader.get(mid) < target) start = mid + 1;
        else end = mid - 1;
    }
    return (reader.get(mid) == target ? mid : -1);
}