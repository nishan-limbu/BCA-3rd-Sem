function addTask() {
    // Get the input value
    var input = document.getElementById("input-task").value;
    var doneList = document.getElementById("done-list");
    // Create a new list item
    var item = document.createElement("li");
  
    // Create a checkbox for the list item
    var checkbox = document.createElement("input");
    checkbox.type = "checkbox";
    checkbox.addEventListener("change", function() {
      if (checkbox.checked) {
        // Move the item to the "Done" list
        item.remove();
        doneList.appendChild(item);
      } else {
        // Move the item back to the "To Do" list
        item.remove();
        todoList.appendChild(item);
      }
    });
    item.appendChild(checkbox);
  
    var text = document.createTextNode(input);
    item.appendChild(text);
  
    // Create a delete button for each list item
    var deleteButton = document.createElement("button");
    var buttonText = document.createTextNode("Delete");
    deleteButton.appendChild(buttonText);
    deleteButton.addEventListener("click", function() {
      item.remove();
    });
    item.appendChild(deleteButton);
  
    // Append the new item to the to do list
    var todoList = document.getElementById("todo-list");
    todoList.appendChild(item);
  
    // Clear the input field
    document.getElementById("input-task").value = "";
  }
 
  