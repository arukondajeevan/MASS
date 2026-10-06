import 'package:flutter/material.dart';
void main() => runApp(const MyApp());
class MyApp extends StatelessWidget {
const MyApp({super.key});
@override
Widget build(BuildContext context) {
return const MaterialApp(
debugShowCheckedModeBanner: false,
home: MyForm(),
);
}
}
class MyForm extends StatefulWidget {
const MyForm({super.key});
@override
State<MyForm> createState() => _MyFormState();
}
class _MyFormState extends State<MyForm> {
final nameController = TextEditingController();
final emailController = TextEditingController();
@override
Widget build(BuildContext context) {
return Scaffold(
appBar: AppBar(title: const Text("Simple Form")),
body: Padding(
padding: const EdgeInsets.all(16.0),
child: Column(
children: [
TextField(
controller: nameController,
decoration: const InputDecoration(labelText: "Name"),
),
TextField(
controller: emailController,
decoration: const InputDecoration(labelText: "Email"),
),
const SizedBox(height: 20),
ElevatedButton(
onPressed: () {
ScaffoldMessenger.of(context).showSnackBar(
SnackBar(content: Text("Name: ${nameController.text}, Email: ${emailController.text}")),
);
},
child: const Text("Submit"),
),
],
),
),
);
}
}
