#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*make personal contact (name, 
mobile number, email, type) and professional contact list (name, mobile number, email, 
office number, address,institute/office, type)*/

typedef enum{FAILURE, SUCCESS} status;

struct personal
{
    char name[50];
    char mobile_number[10];
    char email[50];
    int callduration;
};

struct professional
{
    char name[50];
    char mobile_number[10];
    char email[50];
    char office_number[10];
    char address[50];
    char institute[50];
    int callduration;
};

struct contact
{
    struct personal *per;
    struct professional *pro;
};

struct phonebook
{
    struct contact *con;
    struct phonebook *next;
    struct phonebook *prev;
};

struct megaphonebook
{
    char owname[50]; 
    struct phonebook *ph;
    struct megaphonebook *next;
    struct megaphonebook *prev;
};



//Insert/create contact: 
//a. A new contact to be inserted in the list. Make sure that there is no restriction 
//for the contact with same name

void insertcontact(struct megaphonebook**mhead)
{
    struct phonebook *temp;
    temp = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp->con = (struct contact *)malloc(sizeof(struct contact));
    temp->con->per = (struct personal *)malloc(sizeof(struct personal));
    temp->con->pro = (struct professional *)malloc(sizeof(struct professional));
    temp->next = NULL;
    temp->prev = NULL;
    printf("Enter 0 for personal contact and 1 for professional contact\n");
    int choice=0;
    scanf("%d",&choice);
    if(choice==0)
    {
        printf("Enter name\n");
        scanf("%s",temp->con->per->name);
        printf("Enter mobile number\n");
        scanf("%s",temp->con->per->mobile_number);
        printf("Enter email\n");
        scanf("%s",temp->con->per->email);
        temp->con->pro = NULL;
    }
    else if(choice==1)
    {
        printf("Enter name\n");
        scanf("%s",temp->con->pro->name);
        printf("Enter mobile number\n");
        scanf("%s",temp->con->pro->mobile_number);
        printf("Enter email\n");
        scanf("%s",temp->con->pro->email);
        printf("Enter office number\n");
        scanf("%s",temp->con->pro->office_number);
        printf("Enter address\n");
        scanf("%s",temp->con->pro->address);
        printf("Enter institute/office\n");
        scanf("%s",temp->con->pro->institute);
        temp->con->per = NULL;
    }
    else
    {
        printf("Invalid choice\n");
    }
    if((*mhead)->ph==NULL)
    {
        (*mhead)->ph = temp;
    }
    else
    {
        temp->next = (*mhead)->ph;
        (*mhead)->ph->prev = temp;
        (*mhead)->ph = temp;
    }

}



status chcekifcontactexist(struct megaphonebook *mhead)
{
    status retval=FAILURE;
    struct phonebook *temp;
    temp = (mhead)->ph;
    char name[20];
    char phonumber[20];
    printf("Enter the first name: ");
    scanf("%s",name);
    printf("Enter phonumber\n");
    scanf("%s",phonumber);
    int flag=0;
    while(temp!=NULL && flag==0)
    {
        if(strcmp(temp->con->per->name,name)==0 && strcmp(temp->con->per->mobile_number,phonumber)==0)
        {
            retval=SUCCESS;
            flag=1;
        }
        else if(strcmp(temp->con->pro->name,name)==0 && strcmp(temp->con->pro->mobile_number,phonumber)==0)
        {
            retval=SUCCESS;
            flag=1;
        }
        temp = temp->next;
    }
    return retval;
}

//edit the contact list
void Editcontact(struct megaphonebook **mhead)
{
    struct phonebook *temp;
    temp = (*mhead)->ph;
    char name[20];
    char phonumber[20];
    printf("Enter the first name: ");
    scanf("%s",name);
    printf("Enter phonumber\n");
    scanf("%s",phonumber);
    int flag=0;
    while(temp!=NULL && flag==0)
    {
        if(temp->con->per!=NULL)
        {
            if(strcmp(temp->con->per->name,name)==0 && strcmp(temp->con->per->mobile_number,phonumber)==0)
            {
                printf("Contact found in personal vault");
                printf("Enter 0 for personal contact and 1 for professional contact\n");
                int choice=0;
                scanf("%d",&choice);
                if(choice==0)
                {
                    printf("Enter name\n");
                    scanf("%s",temp->con->per->name);
                    printf("Enter mobile number\n");
                    scanf("%s",temp->con->per->mobile_number);
                    printf("Enter email\n");
                    scanf("%s",temp->con->per->email);
                    temp->con->pro = NULL;
                }
                else if(choice==1)
                {
                    printf("Enter name\n");
                    scanf("%s",temp->con->pro->name);
                    printf("Enter mobile number\n");
                    scanf("%s",temp->con->pro->mobile_number);
                    printf("Enter email\n");
                    scanf("%s",temp->con->pro->email);
                    printf("Enter office number\n");
                    scanf("%s",temp->con->pro->office_number);
                    printf("Enter address\n");
                    scanf("%s",temp->con->pro->address);
                    printf("Enter institute/office\n");
                    scanf("%s",temp->con->pro->institute);
                    temp->con->per = NULL;
                }
                else
                {
                    printf("Invalid choice\n");
                }
                flag=1;
            }
        }
        else if (temp->con->pro!=NULL)
        {
            if(strcmp(temp->con->pro->name,name)==0 && strcmp(temp->con->pro->mobile_number,phonumber)==0)
            {
                printf("Contact found in professional vault");
                printf("Enter 0 for personal contact and 1 for professional contact\n");
                int choice=0;
                scanf("%d",&choice);
                if(choice==0)
                {
                    printf("Enter name\n");
                    scanf("%s",temp->con->per->name);
                    printf("Enter mobile number\n");
                    scanf("%s",temp->con->per->mobile_number);
                    printf("Enter email\n");
                    scanf("%s",temp->con->per->email);
                    temp->con->pro = NULL;
                }
                else if(choice==1)
                {
                    printf("Enter name\n");
                    scanf("%s",temp->con->pro->name);
                    printf("Enter mobile number\n");
                    scanf("%s",temp->con->pro->mobile_number);
                    printf("Enter email\n");
                    scanf("%s",temp->con->pro->email);
                    printf("Enter office number\n");
                    scanf("%s",temp->con->pro->office_number);
                    printf("Enter address\n");
                    scanf("%s",temp->con->pro->address);
                    printf("Enter institute/office\n");
                    scanf("%s",temp->con->pro->institute);
                    temp->con->per = NULL;
                }
                else
                {
                    printf("Invalid choice\n");
                }
                flag=1;
            }
        }
        else
        {
            printf("Not a node");
        }
        temp = temp->next;
    }
    if(flag==0)
    {
        printf("Contact Not found");
    }
}


//delete the contact in the list

void deletecontact(struct megaphonebook **mhead)
{
    struct phonebook *temp;
    temp = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp = (*mhead)->ph;
    char name[50];
    char mobile_number[10];
    printf("Enter the name of the contact: ");
    scanf("%s", name);
    printf("Enter the mobile number of the contact: ");
    scanf("%s", mobile_number);
    int flag=0;
    while(temp != NULL && flag==0)
    {
        if(temp->con->per != NULL)
        {
            if(strcmp(temp->con->per->name,name)==0 && strcmp(temp->con->per->mobile_number,mobile_number)==0)
            {
                if(temp->prev == NULL)
                {
                    (*mhead)->ph = temp->next;
                    free(temp);
                    flag=1;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                    flag=1;
                }
            }
        }
        else if(temp->con->pro != NULL)
        {
            if(strcmp(temp->con->pro->name,name)==0 && strcmp(temp->con->pro->mobile_number,mobile_number)==0)
            {
                if(temp->prev == NULL)
                {
                    (*mhead)->ph = temp->next;
                    free(temp);
                    flag=1;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                    flag=1;
                }
            }

        }
        else
        {
            return;
        }
        temp = temp->next;
    }
    if(flag==0)
    {
        printf("Contact not found\n");
    }

}

        

//search the contact in the list

void Searchcontact(struct megaphonebook *mhead)
{
    struct phonebook *temp;
    temp = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp = (mhead)->ph;
    char name[50];
    char mobile_number[10];
    printf("Enter the name of the contact: ");
    scanf("%s", name);
    printf("Enter the mobile number of the contact: ");
    scanf("%s", mobile_number);
    int flag=0;
    while(temp != NULL && flag==0)
    {
        if(temp->con->per!=NULL)
        {
            if(strcmp(temp->con->per->name,name)==0 && strcmp(temp->con->per->mobile_number,mobile_number)==0 )
            {
                printf("Name: %s\n",temp->con->per->name);
                printf("Mobile Number: %s\n",temp->con->per->mobile_number);
                printf("Email: %s\n",temp->con->per->email);
                printf("\n");
                flag=1;
                
            }
        }
        else if (temp->con->pro!=NULL)
        {
            if(strcmp(temp->con->pro->name,name)==0 && strcmp(temp->con->pro->mobile_number,mobile_number)==0 )
            {
                printf("Name: %s\n",temp->con->pro->name);
                printf("Mobile Number: %s\n",temp->con->pro->mobile_number);
                printf("Email: %s\n",temp->con->pro->email);
                printf("Office Number: %s\n",temp->con->pro->office_number);
                printf("Address: %s\n",temp->con->pro->address);
                printf("Institute/Office: %s\n",temp->con->pro->institute);
                printf("\n");
                flag=1;
            }
        }
        temp = temp->next;
    }
    if(flag==0)
    {
        printf("Contact not found\n");
    }
}



void insertphonenode(struct megaphonebook **mhead,struct phonebook *temp)
{
    if((*mhead)->ph==NULL)
    {
        (*mhead)->ph= temp;
    }
    else
    {
        temp->next = (*mhead)->ph;
        (*mhead)->ph->prev = temp;
        (*mhead)->ph = temp;
    }
    printf("inserted");
}

void deletephonenode(struct megaphonebook **mhead,struct phonebook *temp)
{
    if(temp->prev == NULL)
    {
        (*mhead)->ph = temp->next;
    }
    else if(temp->next ==NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    printf("deleted");
}



void sortonpersonalandprofessional(struct megaphonebook **mhead)
{
    int choice;
    printf("Enter 1 to sort for professional first\n");
    printf("Enter 2 to sort for personal first\n");
    scanf("%d",&choice);
    struct phonebook *temp,*temp1;
    temp=(*mhead)->ph;
    if(choice==1)
    {
        while(temp!=NULL)
        {
            if(temp->con->pro!=NULL)
            {
                printf("Entering--------");
                temp1=temp;
                deletephonenode(mhead,temp);
                insertphonenode(mhead,temp1);
                temp=temp->next;
                continue;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    else if(choice==2)
    {
        while(temp!=NULL)
        {
            if(temp->con->per!=NULL)
            {
                printf("Entering--------");
                temp1=temp;
                deletephonenode(mhead,temp);
                insertphonenode(mhead,temp1);
                temp=temp->next;
                continue;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    else
    {
        printf("Invalid choice\n");
    }
}



//display the contact list with porfessional and personal or all

void Display(struct megaphonebook *mhead)
{
    struct phonebook *temp;
    temp = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp = (mhead)->ph;
    int choice;
    printf("Enter 1 to display all contacts\n");
    printf("Enter 2 to display professional contacts\n");
    printf("Enter 3 to display personal contacts\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        while(temp != NULL)
        {
            if(temp->con->per != NULL)
            {
                printf("Name: %s\n",temp->con->per->name);
                printf("Mobile Number: %s\n",temp->con->per->mobile_number);
                printf("Email: %s\n",temp->con->per->email);
                printf("\n");
            }
            else
            {
                printf("Name: %s\n",temp->con->pro->name);
                printf("Mobile Number: %s\n",temp->con->pro->mobile_number);
                printf("Email: %s\n",temp->con->pro->email);
                printf("Office Number: %s\n",temp->con->pro->office_number);
                printf("Address: %s\n",temp->con->pro->address);
                printf("Institute: %s\n",temp->con->pro->institute);
                printf("\n");
            }
            temp = temp->next;
        }
    }
    else if(choice==2)
    {
        while(temp != NULL)
        {
            if(temp->con->per != NULL)
            {
                temp = temp->next;
            }
            else
            {
                if(temp->con->pro != NULL)
                {
                    printf("Name: %s\n",temp->con->pro->name);
                    printf("Mobile Number: %s\n",temp->con->pro->mobile_number);
                    printf("Email: %s\n",temp->con->pro->email);
                    printf("Office Number: %s\n",temp->con->pro->office_number);
                    printf("Address: %s\n",temp->con->pro->address);
                    printf("Institute: %s\n",temp->con->pro->institute);
                }
                temp = temp->next;
            }
        }
    }
    else if(choice==3)
    {
        while(temp != NULL)
        {
            if(temp->con->pro != NULL)
            {
                temp = temp->next;
            }
            else
            {
                if(temp->con->per != NULL)
                {
                    printf("Name: %s\n",temp->con->per->name);
                    printf("Mobile Number: %s\n",temp->con->per->mobile_number);
                    printf("Email: %s\n",temp->con->per->email);
                    
                }
                temp = temp->next;
            }
        }
    }
}

//merge two linked list based on name and phone number

void merge(struct megaphonebook **mhead1,struct megaphonebook **mhead2)
{
    struct phonebook *temp1,*temp2,*temp3;
    temp1 = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp2 = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp3 = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp1 = (*mhead1)->ph;
    temp2 = (*mhead2)->ph;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(strcmp(temp1->con->per->name,temp2->con->per->name)<0)
        {
            temp3->con = temp1->con;
            temp3->next = temp1->next;
            temp1->next = temp3;
            temp3->prev = temp1;
            temp1 = temp3;
            temp1 = temp1->next;
        }
        else if(strcmp(temp1->con->per->name,temp2->con->per->name)>0)
        {
            temp3->con = temp2->con;
            temp3->next = temp2->next;
            temp2->next = temp3;
            temp3->prev = temp2;
            temp2 = temp3;
            temp2 = temp2->next;
        }
        else
        {
            if(strcmp(temp1->con->per->mobile_number,temp2->con->per->mobile_number)<0)
            {
                temp3->con = temp1->con;
                temp3->next = temp1->next;
                temp1->next = temp3;
                temp3->prev = temp1;
                temp1 = temp3;
                temp1 = temp1->next;
            }
            else
            {
                temp3->con = temp2->con;
                temp3->next = temp2->next;
                temp2->next = temp3;
                temp3->prev = temp2;
                temp2 = temp3;
                temp2 = temp2->next;
            }
        }
    }
    if(temp1 == NULL)
    {
        temp1->next = temp2;
        temp2->prev = temp1;
    }
    else
    {
        temp1->next = temp2;
        temp2->prev = temp1;
    }
}


//remove duplicate contact from the list

void removedup(struct megaphonebook **mhead)
{
    struct phonebook *temp,*dup;
    temp = (struct phonebook *)malloc(sizeof(struct phonebook));
    temp = (*mhead)->ph;
    if((*mhead)->ph==NULL)
    {
        printf("List is Empty");
        return ;
    }
    int nofdup=0;
    while(temp != NULL && temp->next!=NULL)
    {
        if(temp->con->per!=NULL && temp->next->con->per!=NULL)
        {
            if(strcmp(temp->con->per->name,temp->next->con->per->name)==0 && strcmp(temp->con->per->mobile_number,temp->next->con->per->mobile_number)==0)
            {
                printf("DUPfound");
                dup = temp->next;
                if(dup->next==NULL)
                {
                    dup->prev->next = NULL;
                    nofdup++;
                }
                else if(dup->prev==NULL)
                {
                    dup->next->prev = NULL;
                    (*mhead)->ph = dup->next;
                    nofdup++;
                }
                else
                {
                    dup->prev->next = dup->next;
                    dup->next->prev = dup->prev;
                    nofdup++;
                }
                temp=temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        else if (temp->con->pro!=NULL && temp->next->con->pro!=NULL)
        {
            if(strcmp(temp->con->pro->name,temp->next->con->pro->name)==0 && strcmp(temp->con->pro->mobile_number,temp->next->con->pro->mobile_number)==0)
            {
                dup = temp->next;
                if(dup->next==NULL)
                {
                    dup->prev->next = NULL;
                    
                    nofdup++;
                }
                else if(dup->prev==NULL)
                {
                    dup->next->prev = NULL;
                    (*mhead)->ph = dup->next;
                    
                    nofdup++;
                }
                else
                {
                    dup->prev->next = dup->next;
                    dup->next->prev = dup->prev;
                    nofdup++;
                }
                
                temp=temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        else if(temp->con->per!=NULL && temp->next->con->pro!=NULL)
        {
            if(strcmp(temp->con->per->name,temp->next->con->pro->name)==0 && strcmp(temp->con->per->mobile_number,temp->next->con->pro->mobile_number)==0)
            {
                dup = temp->next;
                if(dup->next==NULL)
                {
                    dup->prev->next = NULL;
                    
                    nofdup++;
                }
                else if(dup->prev==NULL)
                {
                    dup->next->prev = NULL;
                    (*mhead)->ph = dup->next;
                    
                    nofdup++;
                }
                else
                {
                    dup->prev->next = dup->next;
                    dup->next->prev = dup->prev;
                    
                    nofdup++;
                }
                
                temp=temp->next;

            }
            else
            {
                temp = temp->next;
            }
        }
        else if(temp->con->pro!=NULL && temp->next->con->per!=NULL)
        {
            if(strcmp(temp->con->pro->name,temp->next->con->per->name)==0 && strcmp(temp->con->pro->mobile_number,temp->next->con->per->mobile_number)==0)
            {
                dup = temp->next;
                if(dup->next==NULL)
                {
                    dup->prev->next = NULL;
                    nofdup++;
                }
                else if(dup->prev==NULL)
                {
                    dup->next->prev = NULL;
                    (*mhead)->ph = dup->next;
                    
                    nofdup++;
                }
                else
                {
                    dup->prev->next = dup->next;
                    dup->next->prev = dup->prev;
                    
                    nofdup++;
                }
                
                temp=temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        else
        {
            temp=temp->next;
        }  
    }

    printf("Duplicates removed %d \n",nofdup);
}




void addnewowner(struct megaphonebook **head)
{
    struct megaphonebook *temp;
    temp = (struct megaphonebook *)malloc(sizeof(struct megaphonebook));
    printf("Enter owner name\n");
    scanf("%s",temp->owname);
    temp->next = NULL;
    temp->prev = NULL;
    temp->ph = NULL;
    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

void removeowner(struct megaphonebook **head)
{
    struct megaphonebook *temp;
    temp = (struct megaphonebook *)malloc(sizeof(struct megaphonebook));
    temp = *head;
    char name[50];
    printf("Enter owner name\n");
    scanf("%s",name);
    while(temp != NULL)
    {
        if(strcmp(temp->owname,name)==0)
        {
            if(temp->next == NULL && temp->prev == NULL)
            {
                *head = NULL;
            }
            else if(temp->next == NULL)
            {
                temp->prev->next = NULL;
            }
            else if(temp->prev == NULL)
            {
                temp->next->prev = NULL;
                *head = temp->next;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            printf("Owner removed\n");
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void printownerlist(struct megaphonebook **head)
{
    struct megaphonebook *temp;
    temp = (struct megaphonebook *)malloc(sizeof(struct megaphonebook));
    temp = *head;
    if(*head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%s\n",temp->owname);
            temp = temp->next;
        }
    }
}

struct megaphonebook *navialter(struct megaphonebook *ownerlisthead, char *input)
{
    struct megaphonebook *temp;
    temp = (struct megaphonebook *)malloc(sizeof(struct megaphonebook));
    temp = ownerlisthead;
    while(temp != NULL)
    {
        if(strcmp(temp->owname,input)==0)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}




int main()
{
    struct megaphonebook *ownerlisthead=NULL,*navigator=NULL;
    addnewowner(&ownerlisthead);
    navigator=ownerlisthead;
    int choice;
    int i=0,j=0;
    char input[50];
    int counter=0;
    int asds=1;
    char owner1[50];
    char owner2[50];
    struct megaphonebook *mergehead1,*mergehead2;
    while(1)
    {
        printf("------------------------------\n");
        printf("Enter 1 to add contact\n");
        printf("Enter 2 to remove contact\n");
        printf("Enter 3 to search contact\n");
        printf("Enter 4 to display contact\n");
        printf("Enter 5 to no of contacts\n");
        printf("Enter 6 to remove duplicate contact sort once before this.\n");
        printf("Enter 7 to edit existing contact\n");
        printf("Enter 8 o check whether contact exist or not\n");
        printf("Enter 9 to merge two owners\n");
        printf("Enter 10 to sort on personal & professional\n");
        printf("Enter 11 to change owner\n");
        printf("Enter 12 to add owner list\n");
        printf("Enter 13 to remove owner list\n");
        printf("Enter 14 to display owner list\n");
        printf("Enter 15 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertcontact(&navigator);
                counter+=1;
                break;
            case 2:
                deletecontact(&navigator);
                counter-=1;
                break;
            case 3:
                Searchcontact(navigator);
                break;
            case 4:
                Display(navigator);
                break;
            case 5:
                printf("%d",counter);
                break;
            case 6:
                removedup(&navigator);
                break;
            case 7:
                Editcontact(&navigator);
                break;
            case 8:
                chcekifcontactexist(navigator);
                break;
            case 9:
                printf("Enter name of owner 1:\n");
                scanf("%s",owner1);
                printf("Enter name of owner 2:\n");
                scanf("%s",owner2);
                mergehead1 = navialter(ownerlisthead,owner1);
                mergehead2 = navialter(ownerlisthead,owner2);
                merge(mergehead1,mergehead2);
                break;
            case 10:
                sortonpersonalandprofessional(&navigator);
                break;
            case 11:
                printf("Enter name of the owner  u want to change\n");
                scanf("%s",input);
                navigator=navialter(ownerlisthead,input);
                break;
            case 12:
            	addnewowner(&ownerlisthead);
				break;
            case 13:
            	removeowner(&ownerlisthead);
                break;
            case 14:
                printownerlist(&ownerlisthead);
                break;
            case 15:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}







