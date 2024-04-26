// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0;

contract Factory { // Exercise 1
    uint idDigits = 16; // Exercise 2
    uint idModulus = uint(10 ** idDigits); // Exercise 3
    

    // Exercise 4
    struct Product {
        uint idProduct;
        string Name;
    }

    // Exercise 5
    Product[] public smartProduct;

    // Exercise 6 - Creating smart products
    
    // Exercise 9 - Declare the NewProduct event
    event NewProduct(uint ArrayProductId, string name, uint id);

    function _createProduct(string memory _name, uint _NewProduct) private { 
        // Push the new product to the array and capture the result
        smartProduct.push(Product(_NewProduct, _name));
        // Calculate the actual product ID by subtracting 1 from the length
        uint productId = smartProduct.length - 1;
        // Emit the NewProduct event with the product's details
        emit NewProduct(_NewProduct, _name, productId);
    }

    // Exercise 7
    function _generateRandomId(string memory _Str) internal view returns(uint){

    //Exercise 8
         uint rand = uint(keccak256(abi.encodePacked(_Str)));
        return rand % idModulus;
    }
    function createRandomProduct(string memory _name) public  {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }

    // Exercise 10
    mapping (uint => address) public productToOwner;
    mapping (address => uint) ownerProductCount;
    
    // Exercise 11 
    //New function to assign ownership of a product (productId is the parameter taken)
     function Ownership(uint _productId) public {
    
    // Check if the product exists and ensure the caller does not already own the product
        require(msg.sender != productToOwner[_productId], "You already own this product");
        productToOwner[_productId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }
    // Exerrcise 12

    // This function is used to get products owned by a specific owner
    // It takes an address _owner as a parameter, which represents the owner whose products we want to retrieve.
     function getProductsByOwner (address _owner) external view returns (uint[] memory) {
    
    // Initialize a counter to keep track of the index in the result array     
         uint counter = 0;

    // This will hold the IDs of the products owned by _owner.     
         uint[] memory result = new uint[](ownerProductCount[_owner]);

    // Iterate through all the products in the smartProduct array
        for (uint i = 0; i < smartProduct.length; i++) {

    // For each product, we check if the owner of the product is the same as _owner.
            if (productToOwner[i] == _owner) {
    
    // If a match is found, add the product's ID to the result array at the current counter index.
                result[counter] = i;

     // Increment the counter to move to the next position in the result array
                counter++;
            }
        }
     // Return the result array containing the IDs of all products owned by the _owner
        return result;
    }

 // Exercise 14
   
 // This Mapping is used to store user's age
    mapping(uint => uint) public age;

    // This Function modifier is used to check if a user is older than a certain age
    modifier olderThan(uint _age, uint _userId) {
        require(age[_userId] >= _age, "User is not old enough");
        _;
    }

    // Function to validate if a user is an adult (18 years old or older)
    function validationUsers(uint _userId) public view olderThan(18, _userId) {
        // Function body is left blank as stated in the exercise
    }

}
