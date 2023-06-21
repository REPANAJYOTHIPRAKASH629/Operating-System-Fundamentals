                                                      /* mvt   */
#include<stdio.h>

void main()
{
        int ms,mp[10],i,temp,n=0;
        char ch='y';

        printf("\nEnter te total memory available (in Bytes)--");
        scanf("%d",&ms);
        temp=ms;
        for(i=0;ch=='y';i++,n++)
        {
                printf("\nEnter the total memory available %d(in Bytes)-- ",i+1);
                scanf("%d",&mp[i]);

                if(mp[i]<=temp)
                {
                        printf("\nMemory is allocated for Process %d",i+1);
                        temp=temp-mp[i];
                }
                else
                {
                        printf("\nMemory is Full");
                        break;
                }
                printf("\nDo you want to continue (y/n)-- ");
                scanf("%c",&ch);
        }
        printf("\n\nTotal Memory Available -- %d",ms);
        printf("\n\n\tPROCESS\t\tMEMORY ALLOCATED ");
        for(i=0;i<n;i++)
        printf("\n\t%d\t\t%d",i+1,mp[i]);
        printf("\n\nTotal Memory Allocated is %d",ms-temp);
        printf("\nTotal External Fragmentaation is %d",temp);
}




                                                      /* mft   */

#include<stdio.h>
void main()
{
        int ms,bs,nob,ef,n,mp[10],tif=0;
        int i,p=0;

        printf("Enter the total memory available (in Bytes) -- ");
        scanf("%d",&ms);
        printf("Enter the block size(in Bytes) -- ");
        scanf("%d",&bs);
        nob=ms/bs;
        ef=ms-nob*bs;
        printf("\nEnter the number of processes -- ");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
                printf("Enter the memory required for process %d(in Bytes)-- ",i+1);
                scanf("%d",&mp[i]);
        }
        printf("\n No. of Blocks available in memory -- %d",nob);
        printf("\n\nPROCESS\tMEMORY\tREQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

        for(i=0;i<n&&p<nob;i++)
        {
                printf("\n %d\t\t%d",i+1,mp[i]);
                if(mp[i]>bs)
                {
                        printf("\t\tNO\t\t---");
                }
                else
                {
                        printf("\t\tYES\t%d",bs-mp[i]);
                        tif=tif+bs-mp[i];
                        p++;
                }
        }
        if(i<n)
        printf("\nMemory is Full,Remaining Processes cannot be accommodated");
        printf("\n\nTotal Internal Fragmentation is %d",tif);
        printf("\nTotal External Fragmentation is %d",ef);
}

