#recursive approach

def TowerOfHanoi(n , source, destination, auxiliary):
    if n==1:
        print ("Moving disk 1 from source",source,"to destination",destination)
        return
    TowerOfHanoi(n-1, source, auxiliary, destination)
    print ("Moving disk",n,"from source",source,"to destination",destination)
    TowerOfHanoi(n-1, auxiliary, destination, source)
