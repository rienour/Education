# Example Python Code to Insert a Document 

from pymongo import MongoClient 
from bson.objectid import ObjectId 

class AnimalShelter(object): 
    """ CRUD operations for Animal collection in MongoDB """ 

    def __init__(self, user, password): 
        # Initializing the MongoClient. This helps to access the MongoDB 
        # databases and collections. This is hard-wired to use the aac 
        # database, the animals collection, and the aac user. 
        # 
        # You must edit the password below for your environment. 
        # 
        # Connection Variables 
        # 
        HOST = 'localhost' 
        PORT = 27017 
        DB = 'aac' 
        COL = 'animals' 
        # 
        # Initialize Connection 
        # 
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (user,password,HOST,PORT)) 
        self.database = self.client['%s' % (DB)] 
        self.collection = self.database['%s' % (COL)] 

    # Create a method to return the next available record number for use in the create method
            
    def create(self, data: dict) -> bool:
        """ This method handles inserting a single record into the database

        :param data: dictionary of values to pass as the insert options
        """
        if data is not None: 
            result = self.database.animals.insert_one(data)  # data should be dictionary             
            return result.acknowledged
        else: 
            raise Exception("Nothing to save, because data parameter is empty") 

    def read_many(self, filter: dict = {}) -> list:
        """ This method handles querying the database and returning all records
        that meet the provided filter

        :param filter: dictionary of values to pass as the filter
        """
        animals = list()
        cursor = self.database.animals.find(filter)
        # Aggregate the results into a single list
        for animal in cursor:
           animals.append(animal) 
        return animals

    def update_many(self, filter: dict, fields: dict) -> int:
        """ This method handles updating a records in the database that meet
	the supplied fields

        :param fields: dictionary of values to pass as the filter for update options
	:param data: dictionary of the values to perform the update on
        """
        if fields is not None: 
            result = self.database.animals.update_many(filter, fields)  # filter and fields should be dictionary             
            return result.modified_count
        else: 
            raise Exception("Nothing to update, because data parameter is empty") 

    def delete_many(self, filter: dict) -> int:
        """ This method handles updating a records in the database that meet
	the supplied fields

        :param fields: dictionary of values to pass as the filter for update options
	:param data: dictionary of the values to perform the update on
        """
        if filter is not None: 
            result = self.database.animals.delete_many(filter)  # filter should be dictionary             
            return result.deleted_count
        else: 
            raise Exception("Nothing to delete, because filter parameter is empty") 
