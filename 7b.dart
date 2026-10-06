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
final _formKey = GlobalKey<FormState>();
final nameController = TextEditingController();
final emailController = TextEditingController();
@override
Widget build(BuildContext context) {
return Scaffold(
appBar: AppBar(title: const Text("Simple Form")),
body: Padding(
padding: const EdgeInsets.all(16.0),
child: Form(
key: _formKey,
child: Column(
children: [
TextFormField(
controller: nameController,
decoration: const InputDecoration(labelText: "Name"),
validator: (value) => value == null || value.isEmpty ? "Enter your name" : null,
),
TextFormField(
controller: emailController,
decoration: const InputDecoration(labelText: "Email"),
keyboardType: TextInputType.emailAddress,
validator: (value) => value != null && !value.contains("@") ? "Invalid email" : null,
),
const SizedBox(height: 20),
ElevatedButton(
onPressed: () {
if (_formKey.currentState!.validate()) {
ScaffoldMessenger.of(context).showSnackBar(
SnackBar(content: Text("Hello, ${nameController.text}!")),
);
}
},
child: const Text("Submit"),
),
],
),
),
),
);
}
}
