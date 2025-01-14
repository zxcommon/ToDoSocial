import "./App.css";

import { collection, addDoc, getDocs, getFirestore } from "firebase/firestore";
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
const firebaseConfig = {
  apiKey: "AIzaSyA4wMaw7aQ9Us8yoZ3ODm_J5jqOxnGM9B4",
  authDomain: "todosocial-6d41c.firebaseapp.com",
  projectId: "todosocial-6d41c",
  storageBucket: "todosocial-6d41c.firebasestorage.app",
  messagingSenderId: "191911532440",
  appId: "1:191911532440:web:6b7ee0d8f4ef4a42c27ded",
  measurementId: "G-M2374MNWGT",
};

const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);
const db = getFirestore(app);
function App() {
  const addUser = async () => {
    try {
      // Ссылка на коллекцию `users`
      const usersRef = collection(db, "users");

      // Добавление нового пользователя
      const docRef = await addDoc(usersRef, {
        name: "John Doe",
        password: "securePassword123",
      });

      console.log("Документ добавлен с ID:", docRef.id);
    } catch (e) {
      console.error("Ошибка добавления документа: ", e);
    }
  };

  const fetchUsers = async () => {
    try {
      const usersRef = collection(db, "users");
      const querySnapshot = await getDocs(usersRef);

      querySnapshot.forEach((doc) => {
        console.log(`${doc.id} =>`, doc.data());
      });
    } catch (e) {
      console.error("Ошибка получения документов: ", e);
    }
  };

  return (
    <div>
      <h1>Firebase йцу Test</h1>
      <button onClick={addUser}>Добавить пользователя</button>
      <button onClick={fetchUsers}>Получить пользователей</button>
    </div>
  );
}

export default App;
